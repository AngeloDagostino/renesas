
/*******************************************************************************
* File Name    : mtu_pwm_demo_main.c
* Version      : 1.0 
* Device(s)	   : RX63N 
* Tool-Chain   : Renesas RX Standard Toolchain 1.0.0
* H/W Platform : YRDKRX63N 
* Description  : This is a basic entry point for the MTU PWM mode1 demo. 
*              : This sample application sets up a MTU channel (MTIOC4B)   
*              : to generate a pulse-width modulated waveform (PWM wave)
*              : on an output pin (PIN 25 of header JN2) that directly 
*              : can drives an electric load with a variable voltage 
*              : level between 0 and 3.3V. 
*              : A function named "Volt_2_PWMduty" generate a proper PWM
*              : signal having a duty-cycle such as the output voltage level 
*              : (range 0-3.3V) is the desired voltage level in volt 
*              : In addition, an interupt service routine changes
*              : the PWM duty cycle and toggles the port pins that drive 
*              : the channel.
*
* Operation	   : 1. Compile and download the sample code. Click 'Reset Go'
*                   to start the software.   
*                2. Observe PWM waveform at header JN2 pin 24 with an
*                   oscilloscope (GND on header BEAGLE PORT pin 2 or 10).
*
* note:        : Demo runs continuously.
*******************************************************************************/

/*****************************************************************************
* History : DD.MM.YYYY  Version  Description               Author
*         : 01.09.2014  1.00     First Release commented   Ferretti Matteo
*******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <machine.h>
#include "platform.h"
#include "mtu_pwm_mode1_demo.h"
#include "CMT.h"
#include "S12ADC.h"

//double Desired_Volt = 2 ; /* desired output Voltage (admissible range 0 - 3.3V)

/******************************************************************************
* Function name: main
* Description  : Main program function. Initializes the LCD, the debug console,
*                and the MTU. Then it remains in an infinite while loop. The
*                demo executes continuously. 
* Arguments    : none
* Return value : none
******************************************************************************/
void main(void)
{
    /* Initialize LCD */
    lcd_initialize();
    
    /* Clear LCD */
    lcd_clear();
    
    /* Display message on LCD */
    lcd_display(LCD_LINE1, " YRDKRX63N  ");
    lcd_display(LCD_LINE2, "MTU PWM Demo");
    lcd_display(LCD_LINE3, "ch. MTIOC4A ");
    lcd_display(LCD_LINE4, "on out: PE2 ");    
    lcd_display(LCD_LINE5, "header: JN2 ");
    lcd_display(LCD_LINE6, "pin n.: 23  ");
    lcd_display(LCD_LINE7, "signal: PWM ");
    lcd_display(LCD_LINE8, "            ");

    /*  STDOUT is routed through the virtual console window tunneled through 
        the JTAG debugger. Open the console window in HEW to see the output. */
    printf("This is the debug console\r\n");

    mtu_initialize();   /* Set up the MTU. */
    
    mtu_start();        /* Start the PWM demo.*/

    S12ADC_init();
	S12ADC_start();

	/* Start the CMT timer to read results & update the display */
	CMT_init(100);	//100ms

	///////////////////////// IL Volt_2_PWMduty ora sta nel CMT.c
    //Volt_2_PWMduty(Desired_Volt);

} /* End of function main() */

/*******************************************************************************
* End of file: mtu_pwm_demo_main.c
*******************************************************************************/
