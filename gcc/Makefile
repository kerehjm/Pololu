
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif
	
	ifeq ($(shell uname), Darwin)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
	app \
	hal/buttons \
	hal/debug \
	hal/leds \
	hal/motors \
	hw/adcs \
	hw/pins \
	hw/sensors \
	hw/timers \
	hw/uart

# List the object files
OBJS +=  \
app/main.o \
\
hal/buttons/button.o \
hal/buttons/buttonA.o \
hal/buttons/buttonB.o \
hal/buttons/buttonC.o \
hal/buttons/buttonFactory.o \
\
hal/debug/debug.o \
\
hal/leds/led.o \
hal/leds/ledFactory.o \
\
hal/motors/motor.o \
hal/motors/motorFactory.o \
\
hw/adcs/adc.o \
\
hw/pins/pin.o \
hw/pins/pinFactory.o \
hw/pins/pinPortMap.o \
\
hw/sensors/proximitySensor.o \
hw/sensors/reflectanceSensor.o \
hw/sensors/sensor.o \
hw/sensors/sensorFactory.o \
\
hw/timers/timer0.o \
hw/timers/timer1.o \
hw/timers/timer2.o \
hw/timers/timerFactory.o \
\
hw/uart/uart.o


OBJS_AS_ARGS +=  \
"app/main.o" \
\
"hal/buttons/button.o" \
"hal/buttons/buttonA.o" \
"hal/buttons/buttonB.o" \
"hal/buttons/buttonC.o" \
"hal/buttons/buttonFactory.o" \
\
"hal/debug/debug.o" \
\
"hal/leds/led.o" \
"hal/leds/ledFactory.o" \
\
"hal/motors/motor.o" \
"hal/motors/motorFactory.o" \
\
"hw/adcs/adc.o" \
\
"hw/pins/pin.o" \
"hw/pins/pinFactory.o" \
"hw/pins/pinPortMap.o" \
\
"hw/sensors/proximitySensor.o" \
"hw/sensors/reflectanceSensor.o" \
"hw/sensors/sensor.o" \
"hw/sensors/sensorFactory.o" \
\
"hw/timers/timer0.o" \
"hw/timers/timer1.o" \
"hw/timers/timer2.o" \
"hw/timers/timerFactory.o" \
\
"hw/uart/uart.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS += \
"app/main.d" \
\
"hal/buttons/button.d" \
"hal/buttons/buttonA.d" \
"hal/buttons/buttonB.d" \
"hal/buttons/buttonC.d" \
"hal/buttons/buttonFactory.d" \
\
"hal/debug/debug.d" \
\
"hal/leds/led.d" \
"hal/leds/ledFactory.d" \
\
"hal/motors/motor.d" \
"hal/motors/motorFactory.d" \
\
"hw/adcs/adc.d" \
\
"hw/pins/pin.d" \
"hw/pins/pinFactory.d" \
"hw/pins/pinPortMap.d" \
\
"hw/sensors/proximitySensor.d" \
"hw/sensors/reflectanceSensor.d" \
"hw/sensors/sensor.d" \
"hw/sensors/sensorFactory.d" \
\
"hw/timers/timer0.d" \
"hw/timers/timer1.d" \
"hw/timers/timer2.d" \
"hw/timers/timerFactory.d" \
\
"hw/uart/uart.d"

MAKEFILE_DIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
OUTPUT_FILE_NAME :=pololu
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.cpp ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target




$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker
	$(QUOTE)avr-g++$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS)  -Wl,--start-group -lm -Wl,--end-group \
-Wl,-Map="$(OUTPUT_FILE_NAME).map" -Wl,--gc-sections \
-mmcu=atmega328p -B "$(MAKEFILE_DIR)../gcc/dev/atmega328p" \
-L"../gcc/dev/atmega328p/avr5"  \
-l:libatmega328p.a 
	@echo Finished building target: $@

	"avr-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"avr-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"avr-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"avr-size" "$(OUTPUT_FILE_NAME).elf"

# Compiler target(s)




%.o: %.cpp
	@echo Building file: $<
	@echo AVR/GNU C++ Compiler
	$(QUOTE)avr-g++$(QUOTE) -x c++ -DF_CPU=8000000 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu++11 \
-mmcu=atmega328p -B "$(MAKEFILE_DIR)../gcc/dev/atmega328p" \
    -D__mega328P__ \
-I"../hal/buttons" -I"../hal/debug" -I"../hal/leds" -I"../hal/motors" -I"../hw/adcs" -I"../hw/pins" -I"../hw/sensors" -I"../hw/timers" -I"../hw/uart"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo AVR/GNU Assembler
	$(QUOTE)avr-g++$(QUOTE) -x assembler-with-cpp -DF_CPU=8000000 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu++11 \
-mmcu=atmega328p -B "$(MAKEFILE_DIR)../gcc/dev/atmega328p" \
    -D__mega328P__ \
-I"../config" -I"../examples/include" -I"../include" -I"../utils" -I"../utils/assembler" -I"../examples/include" -I"../include" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo AVR/GNU Preprocessing Assembler
	$(QUOTE)avr-g++$(QUOTE) -x assembler-with-cpp -DF_CPU=8000000 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu++11 \
-mmcu=atmega328p -B "$(MAKEFILE_DIR)../gcc/dev/atmega328p" \
    -D__mega328P__ \
-I"../config" -I"../examples/include" -I"../include" -I"../utils" -I"../utils/assembler" -I"../examples/include" -I"../include" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
