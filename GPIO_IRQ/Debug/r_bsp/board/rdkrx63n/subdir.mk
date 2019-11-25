################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../r_bsp/board/rdkrx63n/dbsct.c \
../r_bsp/board/rdkrx63n/flash_options.c \
../r_bsp/board/rdkrx63n/hwsetup.c \
../r_bsp/board/rdkrx63n/lcd.c \
../r_bsp/board/rdkrx63n/lowsrc.c \
../r_bsp/board/rdkrx63n/resetprg.c \
../r_bsp/board/rdkrx63n/sbrk.c \
../r_bsp/board/rdkrx63n/vecttbl.c 

SRC_SRCS += \
../r_bsp/board/rdkrx63n/lowlvl.src 

SRC_DEPS += \
r_bsp/board/rdkrx63n/lowlvl.d 

ASSEMBLER_OBJS += \
r_bsp/board/rdkrx63n/lowlvl.obj 

COMPILER_OBJS += \
r_bsp/board/rdkrx63n/dbsct.obj \
r_bsp/board/rdkrx63n/flash_options.obj \
r_bsp/board/rdkrx63n/hwsetup.obj \
r_bsp/board/rdkrx63n/lcd.obj \
r_bsp/board/rdkrx63n/lowsrc.obj \
r_bsp/board/rdkrx63n/resetprg.obj \
r_bsp/board/rdkrx63n/sbrk.obj \
r_bsp/board/rdkrx63n/vecttbl.obj 

C_DEPS += \
r_bsp/board/rdkrx63n/dbsct.d \
r_bsp/board/rdkrx63n/flash_options.d \
r_bsp/board/rdkrx63n/hwsetup.d \
r_bsp/board/rdkrx63n/lcd.d \
r_bsp/board/rdkrx63n/lowsrc.d \
r_bsp/board/rdkrx63n/resetprg.d \
r_bsp/board/rdkrx63n/sbrk.d \
r_bsp/board/rdkrx63n/vecttbl.d 

# Each subdirectory must supply rules for building sources it contributes
r_bsp/board/rdkrx63n/%.obj: ../r_bsp/board/rdkrx63n/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo r_bsp\board\rdkrx63n\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "r_bsp\board\rdkrx63n\cDepSubCommand.tmp"
	ccrx -subcommand="r_bsp\board\rdkrx63n\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo r_bsp\board\rdkrx63n\cSubCommand.tmp=
	@sed -e "s/^/ /" "r_bsp\board\rdkrx63n\cSubCommand.tmp"
	ccrx -subcommand="r_bsp\board\rdkrx63n\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

r_bsp/board/rdkrx63n/%.obj: ../r_bsp/board/rdkrx63n/%.src 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	@echo r_bsp\board\rdkrx63n\srcDepSubCommand.tmp=
	@sed -e "s/^/ /" "r_bsp\board\rdkrx63n\srcDepSubCommand.tmp"
	asrx -subcommand="r_bsp\board\rdkrx63n\srcDepSubCommand.tmp" -MF="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo r_bsp\board\rdkrx63n\srcSubCommand.tmp=
	@sed -e "s/^/ /" "r_bsp\board\rdkrx63n\srcSubCommand.tmp"
	asrx -subcommand="r_bsp\board\rdkrx63n\srcSubCommand.tmp" -output="$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

