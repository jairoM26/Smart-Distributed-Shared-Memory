################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataComunication/Client.cpp \
../DataComunication/Server.cpp \
../DataComunication/SocketConstants.cpp 

OBJS += \
./DataComunication/Client.o \
./DataComunication/Server.o \
./DataComunication/SocketConstants.o 

CPP_DEPS += \
./DataComunication/Client.d \
./DataComunication/Server.d \
./DataComunication/SocketConstants.d 


# Each subdirectory must supply rules for building sources it contributes
DataComunication/%.o: ../DataComunication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


