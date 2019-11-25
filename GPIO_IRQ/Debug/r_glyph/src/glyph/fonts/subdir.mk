################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../r_glyph/src/glyph/fonts/font_8x8.c 

COMPILER_OBJS += \
r_glyph/src/glyph/fonts/font_8x8.obj 

C_DEPS += \
r_glyph/src/glyph/fonts/font_8x8.d 

# Each subdirectory must supply rules for building sources it contributes
r_glyph/src/glyph/fonts/%.obj: ../r_glyph/src/glyph/fonts/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo r_glyph\src\glyph\fonts\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\glyph\fonts\cDepSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\glyph\fonts\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo r_glyph\src\glyph\fonts\cSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\glyph\fonts\cSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\glyph\fonts\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

