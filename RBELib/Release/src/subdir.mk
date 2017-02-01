################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC.c \
../src/DAC.c \
../src/Debug.c \
../src/SPI.c \
../src/USARTDebug.c \
../src/motors.c \
../src/ports.c \
../src/timer.c 

OBJS += \
./src/ADC.o \
./src/DAC.o \
./src/Debug.o \
./src/SPI.o \
./src/USARTDebug.o \
./src/motors.o \
./src/ports.o \
./src/timer.o 

C_DEPS += \
./src/ADC.d \
./src/DAC.d \
./src/Debug.d \
./src/SPI.d \
./src/USARTDebug.d \
./src/motors.d \
./src/ports.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I.././include -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


