DEFINE_FLAGS=

ARDUINO_LIB=../lib/Arduino/core.a ../lib/Arduino/HIDKeyboardMouseCore.a
FLAGS_COMPILE_MAIN=-c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""
LIBS=-I../lib/Arduino/arduino/avr/cores/arduino -I../lib/Arduino/arduino/avr/variants/leonardo -I../lib/Arduino/libraries/Keyboard/src -I../lib/Arduino/arduino/avr/libraries/HID/src -I../lib/Arduino/libraries/Mouse/src 


FLAGS_LINKING=-w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4 
FLAGS_FILE=-g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""
AVRDUDE=avrdude
AVRDUDE_FLAGS =-Cavrdude.conf -v -patmega32u4 -cusbasp -Pusb 

#FILE=../src/Action.cpp  ../src/Adafruit_NeoPixel.cpp ../src/Controller.cpp ../src/Controller.cpp ../src/Mapping.cpp

main.elf: main.o 
	avr-gcc $(FLAGS_LINKING) -o main.elf main.o test.o $(ARDUINO_LIB) -lm
	avr-size -C --mcu=atmega32u4 main.elf
	
main.o: ../src/main.cpp test.o 
	avr-g++ $(FLAGS_COMPILE_MAIN) $(DEFINE_FLAGS) $(LIBS) ../src/main.cpp -o main.o
	
test.o:
	avr-g++ -c -mmcu=atmega32u4 -DF_CPU=16000000L -Os $(LIBS) ../src/test.cpp -o test.o
	
.phony: clean

clean:
	rm -rf main main.elf  main.hex main.o main.d

.phony: upload

upload: main.elf
	#avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 main.elf main.eep
	#avr-objcopy -O ihex -R .eeprom main.elf main.hex
	avr-objcopy -O ihex -R .eeprom main.elf main.hex
	#avrdude -Cavrdude.conf -v -patmega32u4 -cusbasp -Pusb -U flash:w:main.hex:i
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:main.hex:i 

