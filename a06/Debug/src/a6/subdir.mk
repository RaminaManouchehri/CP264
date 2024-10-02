################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/a6/common.c \
../src/a6/expression.c \
../src/a6/queue.c \
../src/a6/stack.c 

C_DEPS += \
./src/a6/common.d \
./src/a6/expression.d \
./src/a6/queue.d \
./src/a6/stack.d 

OBJS += \
./src/a6/common.o \
./src/a6/expression.o \
./src/a6/queue.o \
./src/a6/stack.o 


# Each subdirectory must supply rules for building sources it contributes
src/a6/%.o: ../src/a6/%.c src/a6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-a6

clean-src-2f-a6:
	-$(RM) ./src/a6/common.d ./src/a6/common.o ./src/a6/expression.d ./src/a6/expression.o ./src/a6/queue.d ./src/a6/queue.o ./src/a6/stack.d ./src/a6/stack.o

.PHONY: clean-src-2f-a6

