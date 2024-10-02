################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/int_array_read.c \
../src/main.c \
../src/sum_integers.c \
../src/sum_three_integers.c 

C_DEPS += \
./src/int_array_read.d \
./src/main.d \
./src/sum_integers.d \
./src/sum_three_integers.d 

OBJS += \
./src/int_array_read.o \
./src/main.o \
./src/sum_integers.o \
./src/sum_three_integers.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/int_array_read.d ./src/int_array_read.o ./src/main.d ./src/main.o ./src/sum_integers.d ./src/sum_integers.o ./src/sum_three_integers.d ./src/sum_three_integers.o

.PHONY: clean-src

