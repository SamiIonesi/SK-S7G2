################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/synergy_gen/blinky_thread.c \
../src/synergy_gen/common_data.c \
../src/synergy_gen/hal_data.c \
../src/synergy_gen/main.c \
../src/synergy_gen/pin_data.c 

SREC += \
Blinky_SK_S7G2.srec 

C_DEPS += \
./src/synergy_gen/blinky_thread.d \
./src/synergy_gen/common_data.d \
./src/synergy_gen/hal_data.d \
./src/synergy_gen/main.d \
./src/synergy_gen/pin_data.d 

OBJS += \
./src/synergy_gen/blinky_thread.o \
./src/synergy_gen/common_data.o \
./src/synergy_gen/hal_data.o \
./src/synergy_gen/main.o \
./src/synergy_gen/pin_data.o 

MAP += \
Blinky_SK_S7G2.map 


# Each subdirectory must supply rules for building sources it contributes
src/synergy_gen/%.o: ../src/synergy_gen/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_SYNERGY_ -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/driver" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/bsp" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/driver/api" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/driver/instances" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/src" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/src/synergy_gen" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/framework/el" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/framework/el" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/src/framework/el/tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

