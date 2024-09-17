################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/user/TIM_IT.cpp \
../Core/Src/user/dc_motor.cpp \
../Core/Src/user/kinematic_model.cpp \
../Core/Src/user/mainpp.cpp \
../Core/Src/user/ros_port.cpp 

OBJS += \
./Core/Src/user/TIM_IT.o \
./Core/Src/user/dc_motor.o \
./Core/Src/user/kinematic_model.o \
./Core/Src/user/mainpp.o \
./Core/Src/user/ros_port.o 

CPP_DEPS += \
./Core/Src/user/TIM_IT.d \
./Core/Src/user/dc_motor.d \
./Core/Src/user/kinematic_model.d \
./Core/Src/user/mainpp.d \
./Core/Src/user/ros_port.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/user/%.o Core/Src/user/%.su Core/Src/user/%.cyclo: ../Core/Src/user/%.cpp Core/Src/user/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kch93/STM32CubeIDE/workspace_1.10.1/STM_Template0715/Core/Inc/user_lib" -I"C:/Users/kch93/STM32CubeIDE/workspace_1.10.1/STM_Template0715/Core/Inc/user_lib/ros_lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-user

clean-Core-2f-Src-2f-user:
	-$(RM) ./Core/Src/user/TIM_IT.cyclo ./Core/Src/user/TIM_IT.d ./Core/Src/user/TIM_IT.o ./Core/Src/user/TIM_IT.su ./Core/Src/user/dc_motor.cyclo ./Core/Src/user/dc_motor.d ./Core/Src/user/dc_motor.o ./Core/Src/user/dc_motor.su ./Core/Src/user/kinematic_model.cyclo ./Core/Src/user/kinematic_model.d ./Core/Src/user/kinematic_model.o ./Core/Src/user/kinematic_model.su ./Core/Src/user/mainpp.cyclo ./Core/Src/user/mainpp.d ./Core/Src/user/mainpp.o ./Core/Src/user/mainpp.su ./Core/Src/user/ros_port.cyclo ./Core/Src/user/ros_port.d ./Core/Src/user/ros_port.o ./Core/Src/user/ros_port.su

.PHONY: clean-Core-2f-Src-2f-user

