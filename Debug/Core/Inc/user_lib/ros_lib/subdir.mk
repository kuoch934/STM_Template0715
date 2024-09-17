################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/user_lib/ros_lib/duration.cpp \
../Core/Inc/user_lib/ros_lib/time.cpp 

OBJS += \
./Core/Inc/user_lib/ros_lib/duration.o \
./Core/Inc/user_lib/ros_lib/time.o 

CPP_DEPS += \
./Core/Inc/user_lib/ros_lib/duration.d \
./Core/Inc/user_lib/ros_lib/time.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/user_lib/ros_lib/%.o Core/Inc/user_lib/ros_lib/%.su Core/Inc/user_lib/ros_lib/%.cyclo: ../Core/Inc/user_lib/ros_lib/%.cpp Core/Inc/user_lib/ros_lib/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kch93/STM32CubeIDE/workspace_1.10.1/STM_Template0715/Core/Inc/user_lib" -I"C:/Users/kch93/STM32CubeIDE/workspace_1.10.1/STM_Template0715/Core/Inc/user_lib/ros_lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-user_lib-2f-ros_lib

clean-Core-2f-Inc-2f-user_lib-2f-ros_lib:
	-$(RM) ./Core/Inc/user_lib/ros_lib/duration.cyclo ./Core/Inc/user_lib/ros_lib/duration.d ./Core/Inc/user_lib/ros_lib/duration.o ./Core/Inc/user_lib/ros_lib/duration.su ./Core/Inc/user_lib/ros_lib/time.cyclo ./Core/Inc/user_lib/ros_lib/time.d ./Core/Inc/user_lib/ros_lib/time.o ./Core/Inc/user_lib/ros_lib/time.su

.PHONY: clean-Core-2f-Inc-2f-user_lib-2f-ros_lib

