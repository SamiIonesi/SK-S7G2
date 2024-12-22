################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/blinky_thread_entry.c \
../src/hal_entry.c 

SREC += \
Blinky_SK_S7G2.srec 

C_DEPS += \
./src/blinky_thread_entry.d \
./src/hal_entry.d 

OBJS += \
./src/blinky_thread_entry.o \
./src/hal_entry.o 

MAP += \
Blinky_SK_S7G2.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_SYNERGY_ -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/driver" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/bsp" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/driver/api" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/driver/instances" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/src" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/src/synergy_gen" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy_cfg/ssp_cfg/framework/el" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/inc/framework/el" -I"C:/Users/iones/e2_studio/workspace/Blinky_SK_S7G2/synergy/ssp/src/framework/el/tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

