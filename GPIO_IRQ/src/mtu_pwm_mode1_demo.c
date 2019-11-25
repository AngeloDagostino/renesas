
/******************************************************************************
 * File Name     : mtu_pwm_mode1_demo.c
 * Version       : 1.00
 * Device(s)	    : RX63N
 * H/W Platform  : YRDKRX63N
 * Description   : Defines MTU functions used for the MTU PWM mode1 demo.
 *               : For this demo, the PWM duty cycle will be computed so that
 *               : the output voltage level (range 0-3.3V) will be the
 *               : desired voltage level defined as input value in volt.
 ******************************************************************************/

/******************************************************************************
 * History : DD.MM.YYYY     Version     Description               Author
 *         : 01.09.2014     1.00        First release commented   Andrea Bonci
 ******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "platform.h"
#include "mtu_pwm_mode1_demo.h"

/******************************************************************************
Macro definitions
 ******************************************************************************/
/* Values used to define the PWM base frequency and the duty cycle limits. */
#define PCLK_FRQ     48000000 /* System Peripheral Clock (PCLK) Frequency in HZ (48 MHz). */
#define BASE_PWM_FRQ 20000    /* Desired PWM Frequency in HZ (Interrupt Frequency of the PWM) (20KHz or 50us) */
#define MAX_DUTY     99       /* Maximum duty cycle percent. */
#define MIN_DUTY     1        /* Minimum duty cycle percent. */
#define MTU4_prescaler 16     /* Prescaler value for Channel MTU4 */ 
/* of Multi Timer Unit 2 (MTU2) peripheral
 * Select from max six internal clock signals
 * PCLK/1, PCLK/4, PCLK/16, PCLK/64, PCLK/256, PCLK/1024
 * (number of clock signals depend on the MTU channel selected, here MTU4)
 * MTU2 peripheral has 2 MTU unit (MTU 1/2) each one having
 * 6 channels (MTU0 to MTU5) and each channel has
 * a 16-bit timer counter
 * Referring to Hardware Manal Chapt.23, Par.23.1, Table 23.2 */

#define V_Max  3.3		     /* Max Output Value in Volt
 * for the Output Channel of the PWM */

/******************************************************************************
Private global variables
 ******************************************************************************/
/* The count value to set the base frequency of the PWM. */
/* practically it is the value to assign to register TGRA which define */
/* the value to compare with TCNT for defining the base period (frequency) of the PWM */

#define g_pwm_base_count (PCLK_FRQ / BASE_PWM_FRQ)

/* A max count value for the PWM width that must not be exceeded. */
/* practically it is the maximum value that TGRB can assume */

const unsigned short g_max_duty_count = ((g_pwm_base_count / 100.0) * MAX_DUTY);

/* A min count value for the PWM width that must not be exceeded. */
/* practically it is the minimum value that TGRB can assume */

const unsigned short g_min_duty_count = ((g_pwm_base_count / 100.0) * MIN_DUTY);


/******************************************************************************
 * Function name : mtu_initialize
 * Description   : Set up an MTU2a timer unit for operating in PWM mode1.
 * Arguments     : none
 * Return Value  : none
 ******************************************************************************/
void mtu_initialize (void)
{
	/* Enable the MTU2a peripheral to operate */
	/* (the peripheral must be enabled before being used).*/
	/* To enable timer of channel MTUi (i=1..4) of the MTU2a */
	/* the register MSTP(MTUi) must be activated, because*/
	/* this register is protected on writing by PRCR protection register, */
	/* before activate MSTP(MTUi) it is necessary:*/
	/* a) to set off the PRCR, */
	/* b) enable desired MTUi (i=1..4) channel (in this case MTU4, i=4)*/
	/* c) to set on the PRCR. */

	/* Disable protection of the Register Write Protection PRCR */
	/* Protect set off (ref. Hardware Manual Chapt.13.1.1)*/

#ifdef PLATFORM_BOARD_RDKRX63N
	SYSTEM.PRCR.WORD = 0xA50B; /* Protect off */
#endif
	/* write A5 (in hexadecimal) to the eight higher-order */
	/* bits and 0B (in hexadecimal) to the eight lower-order */
	/* where B in hexadecimal is equivalent to 1011 in Binary */
	/* therefor it sets PRC3, PRC1 and PRC0 to 1 */

	/* Disable Module Stop Function (MSTP) of timer MTU4 */
	MSTP(MTU4) = 0; /* Power up the MTU4 timer of the MTU2a */

	/* Enable protection of the  Register Write Protection PRCR */
#ifdef PLATFORM_BOARD_RDKRX63N
	SYSTEM.PRCR.WORD = 0xA500; /* Protect on */
#endif

	/* Protect set on  (ref. Hardware Manual Chapt.13.1.1)*/
	/* write A5 (in hexadecimal) to the eight higher-order */
	/* bits and 0B (in hexadecimal) to the eight lower-order */
	/* where B in hexadecimal is equivalent to 1011 in Binary */
	/* therefor it sets PRC3, PRC1 and PRC0 to 1 */



	/* INITIALIZATION OPERATIONS ON MTU4 CHANNEL OF THE MTU2a PERIPHERAL (ref. Hardware Manual Chapt.23)*/
	/* Disable "Timer Start Register" (TSTR) of the MTU4 channel (ref. Hardware Manual Chapt.23.2.14)*/
	MTU.TSTR.BIT.CST4 = 0; /* Stop count of MTU4 Timer Counter (MTU4.TCNT)
							by stopping TSTR register of MTU4
							(ref. Hardware Manual Chapt.23.2.14) */

	/* Enable read/write access to the MTU4 channel and enable PIN TIOC4A/B of the CPU */
	MTU.TRWER.BIT.RWE = 1; /* Enable read/write access to the write-protected MTU3 and MTU4
							by enabling "Timer Read/Write Enable Registers" (TRWER)
							(ref. Hardware Manual Chapt.23.2.16) */
	MTU.TOER.BIT.OE4A = 1; /* Enable MTIOC4A output. In MTU3 and MTU4,
							set TOER prior to setting TIOR.
							by enabling "Timer Output Master Enable Registers" (TOER)
							(ref. Hardware Manual Chapt.23.2.17) */
	// MTU.TOER.BIT.OE4B = 1;
	/* Enable MTIOC4B output. In MTU3 and MTU4,
							set TOER prior to setting TIOR.
							by enabling "Timer Output Master Enable Registers" (TOER)
							(ref. Hardware Manual Chapt.23.2.17) */



	/* setting of P24 as NO I/O port but as MTIOC4A for PWM signals */
	// PROVA LED9
	MPC.PE2PFS.BYTE = 0x01; // 1 defines PE2 to be MTIOC4A, with no IRQ.

	MPC.P24PFS.BYTE = 1;
	/* 1 defines P24 to be MTIOC4A, with no IRQ.
							(ref. Hardware Manual Chapt.22.2.4) */

	/* setting the Port Direction Register (PDR) of PORT2 as Output port */

	PORTE.PDR.BIT.B2 = 1; // Set PE2 as output.

	PORT2.PDR.BIT.B4 = 1;
							/* Set P24 as output.
						 (ref. Hardware Manual Chapt.21.3.1)
						 setting the Port Mode Register (PMR) to use the Pin4 of PORT2
						 as I/O for peripheral function and not as general I/O pin */

	PORTE.PMR.BIT.B2 = 1; // Set PE2 as peripheral function bit

	PORT2.PMR.BIT.B4 = 1; /* Set pin4 of PORT2 as peripheral function pin (not as general I/O)
							//(ref. Hardware Manual Chapt.21.3.4) */





	/* Timer Control Register (TCR)
    b7:b5   CCLR: Counter Clear Source 1 = TCNT cleared by TGRA compare match/input capture 
	                                   2 = TCNT cleared by TGRB compare match/input capture 
    b4:b3   CKEG: Clock Edge           0 = count at rising edge
    b2:b0   TPSC: Time Prescaler       0 = count on PCLK / 1  */
	MTU4.TCR.BYTE = 0x20;  /* Clear on TGRA match. Prescaler = PCLK / 1 setting. */

	/* Timer Mode Register (TMDR)
    b7      ---   Reserved. Always read/write 0.
    b6      BFE - TPUm.TGRE operates normally
    b5      BFB - TPUm.TGRB operates normally
    b4      BFA - TPUm.TGRA operates normally
    b3:b0   MD  - 0 = Normal operation
	              2 = Set PWM mode 1 */
	MTU4.TMDR.BYTE = 0x02;

	/* Timer I/O Control Register (TIORH)
    b7:b4   IOB - 5 = Ouptut: initial 1, 0 at TGRB compare match
    b3:b0   IOA - MTIOC4A pin function:
                6 = output: initial 1, then 1 after TGRA match */
	MTU4.TIORH.BYTE = 0x56;  /* High on TGRA, Low on TGRB. */

	/* Timer I/O Control Register (TIORL)
    b7:b4   IOD - 0 = output: none
    b3:b0   IOC - 0 = output: none  */
	MTU4.TIORL.BYTE = 0x00;

	/* Timer General Registers (TGRx)
	 *  b15:b0 TGRx either output compare or input capture register.
	 *         x may be A, B, C, or D, depending on which registers this MTU has.
	 * TGRA is being used as the PWM base frequency counter.
	 * The count is cleared on match of TCNT to this value.
	 * TGRB is being used as the PWM pulse width counter.
	 * The output level is switched when this count is reached by TCNT. */

	MTU4.TGRA = g_pwm_base_count; /* MTIOC4A: 1 when TCNT gets to TGRA, 0 when TCNT gets to TGRB */

	MTU4.TGRB = g_pwm_base_count / 2; /* Default Starting value for PWM is 50% duty. */

} /* End of function mtu_initialize(). */


/******************************************************************************
 * Function name : mtu_start
 * Description   : Starts the MTU counting operation.
 * Arguments     : none
 * Return Value  : none
 ******************************************************************************/
void mtu_start (void)
{
	MTU4.TCNT = 0x0000; /* Clear counter register */
	MTU.TSTR.BIT.CST4 = 1; /* Start MTU4 */
} /* End of function mtu_start(). */


/******************************************************************************
 * Function name : mtu_stop
 * Description   : Stops the MTU counting operation.
 * Arguments     : none
 * Return Value  : none
 ******************************************************************************/
void mtu_stop (void)
{
	MTU.TSTR.BIT.CST4 = 0; /* Stop MTU4. */
} /* End of function mtu_stop(). */


/******************************************************************************
 * Function name: Volt_2_PWMduty
 * Description  : Sample of PWM duty-cycle generator such that the output
 *                voltage level (range 0-3.3V) will be the desired voltage
 *                level defined as input value in volt.
 * H/W Devices  : Used peripheral            : MTU2a
 *                Used peripheral's channel  : MTU4
 *                Used peripheral's registers: MTU4.TGRA, MTU4.TGRB
 *                Used CPU Pins              : MTIOC4A
 *                Used CPU Output port       : P24
 *                Used Output Header Pins    : JN2 Pin 25
 * Arguments    : desired_output
 * Return value : none
 ******************************************************************************/

////////////// IL desired_output (ovvero il desired_Volt che indicava il valore medio) è calcolato in CMT.c
void Volt_2_PWMduty (double desired_output)
{
	unsigned short int g_duty_count;

	if (desired_output <= 0.0)	 /* if desired_output approximate 0.0 Volt,
	 * (minimumm admissible voltage value
	 * for the output channel) */
	{
		/* setting TGRB to its min value */

		MTU4.TGRB = g_min_duty_count;
	}
	else if (desired_output >= V_Max) /* if desired_output approximate V_Max Volt,
	 * (maximum admissible voltage value
	 * for the output channel) */
	{
		/* setting TGRB to its max value */
		MTU4.TGRB = g_max_duty_count; //MTU4.TGRA + 2;
	}
	else
	{
		/* computation of the desired duty (g_duty_count) based on the  */
		/* desired_output value, it is the value to assign to TGRB register */

		g_duty_count = desired_output*g_max_duty_count/V_Max;

		/* setting TGRB to the computed value g_duty_count */

		MTU4.TGRB = g_duty_count;
	}

} /* End of volt_2_PWMduty. */


/*******************************************************************************
 * End of file: mtu_pwm_mode1_demo.c
 *******************************************************************************/
