CC=
BUILD_PATH=./build
LIB_PATH=./lib

OBJ=Joystick.o LayoutPosition.o CustomLayoutPosition.o


############################################################################
_OBJ=$(patsubst %.o, $(BUILD_PATH)/%.o, $(OBJ))

INCLUDE_PATH_OBJ=$(patsubst %.o, -I$(LIB_PATH)/%/src, $(OBJ))

DEFINE_FLAGS=


ARDUINO_LIB=./lib/Arduino/core.a ./lib/Arduino/HIDKeyboardMouseCore.a
FLAGS_COMPILE_MAIN=-c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""
LIBS=-I./lib/Arduino/arduino/avr/cores/arduino -I./lib/Arduino/arduino/avr/variants/leonardo -I./lib/Arduino/libraries/Keyboard/src -I./lib/Arduino/arduino/avr/libraries/HID/src -I./lib/Arduino/libraries/Mouse/src 

FLAGS_LINKING=-w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4 
FLAGS_FILE=-g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""

AVRDUDE=avrdude
AVRCONF_PATH=.
AVRDUDE_FLAGS =-C$(AVRCONF_PATH)/avrdude.conf -v -patmega32u4 -cusbasp -Pusb 

#FILE=../src/Action.cpp  ../src/Adafruit_NeoPixel.cpp ../src/Controller.cpp ../src/Controller.cpp ../src/Mapping.cpp

LIBS+=$(INCLUDE_PATH_OBJ)

$(BUILD_PATH)/main.elf: $(_OBJ) $(BUILD_PATH)/main.o
	avr-gcc $(FLAGS_LINKING) -o $(BUILD_PATH)/main.elf $(BUILD_PATH)/main.o $(_OBJ) $(ARDUINO_LIB) -lm
	avr-size -C --mcu=atmega32u4 $(BUILD_PATH)/main.elf
	
$(BUILD_PATH)/main.o: ./src/main.cpp 
	avr-g++ $(FLAGS_COMPILE_MAIN) $(DEFINE_FLAGS) $(LIBS) $< -o $@
	
$(BUILD_PATH)/Joystick.o: ./lib/Joystick/src/Joystick.cpp ./lib/Joystick/src/Joystick.h
	avr-g++ -c -mmcu=atmega32u4 -DF_CPU=16000000L -Os $(DEFINE_FLAGS) $(LIBS) $< -o $@

$(BUILD_PATH)/LayoutPosition.o: ./lib/LayoutPosition/src/LayoutPosition.cpp ./lib/LayoutPosition/src/LayoutPosition.h
	avr-g++ -c -mmcu=atmega32u4 -DF_CPU=16000000L -Os $(DEFINE_FLAGS) $(LIBS) $< -o $@

$(BUILD_PATH)/CustomLayoutPosition.o: ./lib/CustomLayoutPosition/src/CustomLayoutPosition.cpp ./lib/CustomLayoutPosition/src/CustomLayoutPosition.h
	avr-g++ -c -mmcu=atmega32u4 -DF_CPU=16000000L -Os $(DEFINE_FLAGS) $(LIBS) $< -o $@


.phony: clean

clean:	
	rm -rf $(BUILD_PATH)/*.o $(BUILD_PATH)/*.elf $(BUILD_PATH)/*.hex $(BUILD_PATH)/*.d

.phony: upload

upload: $(BUILD_PATH)/main.elf
	#avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 main.elf main.eep
	#avr-objcopy -O ihex -R .eeprom main.elf main.hex
	avr-objcopy -O ihex -R .eeprom $< $(BUILD_PATH)/main.hex
	#avrdude -Cavrdude.conf -v -patmega32u4 -cusbasp -Pusb -U flash:w:main.hex:i
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(BUILD_PATH)/main.hex:i 

