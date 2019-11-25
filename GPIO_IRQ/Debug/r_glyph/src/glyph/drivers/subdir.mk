################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../r_glyph/src/glyph/drivers/st7579_lcd.c 

COMPILER_OBJS += \
r_glyph/src/glyph/drivers/st7579_lcd.obj 

C_DEPS += \
r_glyph/src/glyph/drivers/st7579_lcd.d 

# Each subdirectory must supply rules for building sources it contributes
r_glyph/src/glyph/drivers/%.obj: ../r_glyph/src/glyph/drivers/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo r_glyph\src\glyph\drivers\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\glyph\drivers\cDepSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\glyph\drivers\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo r_glyph\src\glyph\drivers\cSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\glyph\drivers\cSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\glyph\drivers\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

