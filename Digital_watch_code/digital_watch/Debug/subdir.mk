################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../delay.c \
../interrupt.c \
../main.c \
../sev_segment.c \
../switches.c \
../timer.c 

OBJS += \
./delay.o \
./interrupt.o \
./main.o \
./sev_segment.o \
./switches.o \
./timer.o 

C_DEPS += \
./delay.d \
./interrupt.d \
./main.d \
./sev_segment.d \
./switches.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


