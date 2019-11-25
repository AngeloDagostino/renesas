################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../r_glyph/src/r_glyph.c \
../r_glyph/src/r_glyph_register.c 

COMPILER_OBJS += \
r_glyph/src/r_glyph.obj \
r_glyph/src/r_glyph_register.obj 

C_DEPS += \
r_glyph/src/r_glyph.d \
r_glyph/src/r_glyph_register.d 

# Each subdirectory must supply rules for building sources it contributes
r_glyph/src/%.obj: ../r_glyph/src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo r_glyph\src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\cDepSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo r_glyph\src\cSubCommand.tmp=
	@sed -e "s/^/ /" "r_glyph\src\cSubCommand.tmp"
	ccrx -subcommand="r_glyph\src\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

