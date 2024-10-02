################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/strings_array.c \
../src/strings_length.c \
../src/strings_with_substring.c 

C_DEPS += \
./src/main.d \
./src/strings_array.d \
./src/strings_length.d \
./src/strings_with_substring.d 

OBJS += \
./src/main.o \
./src/strings_array.o \
./src/strings_length.o \
./src/strings_with_substring.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/main.d ./src/main.o ./src/strings_array.d ./src/strings_array.o ./src/strings_length.d ./src/strings_length.o ./src/strings_with_substring.d ./src/strings_with_substring.o

.PHONY: clean-src

