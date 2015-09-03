################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Smart\ Distributed\ Shared\ Memory.cpp 

OBJS += \
./Smart\ Distributed\ Shared\ Memory.o 

CPP_DEPS += \
./Smart\ Distributed\ Shared\ Memory.d 


# Each subdirectory must supply rules for building sources it contributes
Smart\ Distributed\ Shared\ Memory.o: ../Smart\ Distributed\ Shared\ Memory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Smart Distributed Shared Memory.d" -MT"Smart\ Distributed\ Shared\ Memory.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


