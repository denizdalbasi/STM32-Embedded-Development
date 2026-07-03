################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/%.o: ../Drivers/STM32F4xx_HAL_Driver/Src/%.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

