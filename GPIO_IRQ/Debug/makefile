################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp *.bls *.libelf *.rel *.lbk *.abs *.mi *.jmp *.fsy 1st/*.abs 1st/*.jmp 1st/*.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include r_glyph/src/glyph/drivers/subdir.mk
-include r_glyph/src/glyph/fonts/subdir.mk
-include src/subdir.mk
-include r_glyph/src/glyph/subdir.mk
-include r_glyph/src/subdir.mk
-include r_rspi_rx600/src/subdir.mk
-include r_bsp/board/rdkrx63n/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif 
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif 
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif 
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif 
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif 
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif 
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif 
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif 
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif 
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif 
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif 
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif 
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif 
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif 
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif


-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables
LINKER_OUTPUT_OUTPUTS += \
GPIO_IRQ.abs

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
GPIO_IRQ.lib

CONVERTOR_OUTPUT_OUTPUTS += \
GPIO_IRQ.mot

OBJS := \
$(COMPILER_OBJS) \
$(INDIVIDUAL_COMPILER_OBJS) \
$(ASSEMBLER_OBJS) \
$(CUSTOM_OBJS)

# All Target
all: $(CONVERTOR_OUTPUT_OUTPUTS) GPIO_IRQ.x

	@echo 'Build complete.'

GPIO_IRQ.mot: $(LINKER_OUTPUT_OUTPUTS) 
	@echo 'Invoking: Converter'
	@echo 'Building target:'
	@echo ConverterGPIO_IRQ.tmp=
	@sed -e "s/^/    /" "ConverterGPIO_IRQ.tmp"
	rlink   "GPIO_IRQ.abs" -subcommand="ConverterGPIO_IRQ.tmp"
	@echo 'Finished building target:'
	@echo.


GPIO_IRQ.abs: $(OBJS)  $(ALL_ASMS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) 
	@echo 'Invoking: Linker'
	@echo LinkerGPIO_IRQ.tmp=
	@sed -e "s/^/    /" "LinkerGPIO_IRQ.tmp"
	rlink -subcommand="LinkerGPIO_IRQ.tmp"
	@echo 'Finished building:'
	@echo.


GPIO_IRQ.lib: 
	@echo 'Invoking: Library Generator'
	@echo LibraryGeneratorGPIO_IRQ.tmp=
	@sed -e "s/^/    /" "LibraryGeneratorGPIO_IRQ.tmp"
	lbgrx -subcommand="LibraryGeneratorGPIO_IRQ.tmp"
	@echo 'Finished building:'
	@echo.

GPIO_IRQ.x: GPIO_IRQ.abs
		-C:\Renesas\e2_studio\Utilities\\ccrx\renesas_cc_converter.exe GPIO_IRQ.abs GPIO_IRQ.x

# Other Targets
clean:
	-$(RM) $(LINKER_OUTPUT_OUTPUTS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	-rm -rf r_glyph/src/glyph/drivers/*.obj r_glyph/src/glyph/drivers/*.d r_glyph/src/glyph/drivers/*.asm r_glyph/src/glyph/drivers/*.p r_glyph/src/glyph/drivers/*.pp r_glyph/src/glyph/drivers/*.src r_glyph/src/glyph/drivers/*.jmp r_glyph/src/glyph/drivers/*.lst r_glyph/src/glyph/drivers/*.prn r_glyph/src/glyph/drivers/*.i 
	-rm -rf r_glyph/src/glyph/fonts/*.obj r_glyph/src/glyph/fonts/*.d r_glyph/src/glyph/fonts/*.asm r_glyph/src/glyph/fonts/*.p r_glyph/src/glyph/fonts/*.pp r_glyph/src/glyph/fonts/*.src r_glyph/src/glyph/fonts/*.jmp r_glyph/src/glyph/fonts/*.lst r_glyph/src/glyph/fonts/*.prn r_glyph/src/glyph/fonts/*.i 
	-rm -rf src/*.obj src/*.d src/*.asm src/*.p src/*.pp src/*.src src/*.jmp src/*.lst src/*.prn src/*.i 
	-rm -rf r_glyph/src/glyph/*.obj r_glyph/src/glyph/*.d r_glyph/src/glyph/*.asm r_glyph/src/glyph/*.p r_glyph/src/glyph/*.pp r_glyph/src/glyph/*.src r_glyph/src/glyph/*.jmp r_glyph/src/glyph/*.lst r_glyph/src/glyph/*.prn r_glyph/src/glyph/*.i 
	-rm -rf r_glyph/src/*.obj r_glyph/src/*.d r_glyph/src/*.asm r_glyph/src/*.p r_glyph/src/*.pp r_glyph/src/*.src r_glyph/src/*.jmp r_glyph/src/*.lst r_glyph/src/*.prn r_glyph/src/*.i 
	-rm -rf r_rspi_rx600/src/*.obj r_rspi_rx600/src/*.d r_rspi_rx600/src/*.asm r_rspi_rx600/src/*.p r_rspi_rx600/src/*.pp r_rspi_rx600/src/*.src r_rspi_rx600/src/*.jmp r_rspi_rx600/src/*.lst r_rspi_rx600/src/*.prn r_rspi_rx600/src/*.i 
	-rm -rf r_bsp/board/rdkrx63n/*.obj r_bsp/board/rdkrx63n/*.d r_bsp/board/rdkrx63n/*.asm r_bsp/board/rdkrx63n/*.p r_bsp/board/rdkrx63n/*.pp r_bsp/board/rdkrx63n/*.src r_bsp/board/rdkrx63n/*.jmp r_bsp/board/rdkrx63n/*.lst r_bsp/board/rdkrx63n/*.prn r_bsp/board/rdkrx63n/*.i 
	@echo
	@echo 'Clean complete.'

.PHONY: all clean 
-include ../makefile.targets