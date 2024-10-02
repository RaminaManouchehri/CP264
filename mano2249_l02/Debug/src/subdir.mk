################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/by_index.c \
../src/by_ptr.c \
../src/main.c 

C_DEPS += \
./src/by_index.d \
./src/by_ptr.d \
./src/main.d 

OBJS += \
./src/by_index.o \
./src/by_ptr.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/by_index.d ./src/by_index.o ./src/by_ptr.d ./src/by_ptr.o ./src/main.d ./src/main.o

.PHONY: clean-src

