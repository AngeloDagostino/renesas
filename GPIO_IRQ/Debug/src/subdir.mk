################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/CMT.c \
../src/S12ADC.c \
../src/mtu_pwm_demo_main.c \
../src/mtu_pwm_mode1_demo.c 

COMPILER_OBJS += \
src/CMT.obj \
src/S12ADC.obj \
src/mtu_pwm_demo_main.obj \
src/mtu_pwm_mode1_demo.obj 

C_DEPS += \
src/CMT.d \
src/S12ADC.d \
src/mtu_pwm_demo_main.d \
src/mtu_pwm_mode1_demo.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\cDepSubCommand.tmp"
	ccrx -subcommand="src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\cSubCommand.tmp"
	ccrx -subcommand="src\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

