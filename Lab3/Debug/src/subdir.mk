################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ExpresionManager.cpp \
../src/Factory.cpp \
../src/Lab3.cpp 

OBJS += \
./src/ExpresionManager.o \
./src/Factory.o \
./src/Lab3.o 

CPP_DEPS += \
./src/ExpresionManager.d \
./src/Factory.d \
./src/Lab3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


