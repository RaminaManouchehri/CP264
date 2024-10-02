################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common.c \
../src/expression.c \
../src/expression_ptest.c \
../src/queue.c \
../src/stack.c 

C_DEPS += \
./src/common.d \
./src/expression.d \
./src/expression_ptest.d \
./src/queue.d \
./src/stack.d 

OBJS += \
./src/common.o \
./src/expression.o \
./src/expression_ptest.o \
./src/queue.o \
./src/stack.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/common.d ./src/common.o ./src/expression.d ./src/expression.o ./src/expression_ptest.d ./src/expression_ptest.o ./src/queue.d ./src/queue.o ./src/stack.d ./src/stack.o

.PHONY: clean-src

