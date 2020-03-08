
#Compiling core...

avr-gcc -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring_pulse.S -o ./wiring_pulse.S.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/WInterrupts.c -o ./WInterrupts.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring_analog.c -o ./wiring_analog.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/hooks.c -o ./hooks.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring.c -o ./wiring.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring_digital.c -o ./wiring_digital.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring_pulse.c -o ./wiring_pulse.c.o
avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/wiring_shift.c -o ./wiring_shift.c.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/HardwareSerial1.cpp -o ./HardwareSerial1.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/HardwareSerial.cpp -o ./HardwareSerial.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/CDC.cpp -o ./CDC.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/HardwareSerial0.cpp -o ./HardwareSerial0.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/HardwareSerial2.cpp -o ./HardwareSerial2.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/HardwareSerial3.cpp -o ./HardwareSerial3.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/IPAddress.cpp -o ./IPAddress.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/PluggableUSB.cpp -o ./PluggableUSB.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/Print.cpp -o ./Print.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/Stream.cpp -o ./Stream.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/Tone.cpp -o ./Tone.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/USBCore.cpp -o ./USBCore.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/WMath.cpp -o ./WMath.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/WString.cpp -o ./WString.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/abi.cpp -o ./abi.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/main.cpp -o ./main.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo ../arduino/avr/cores/arduino/new.cpp -o ./new.cpp.o

avr-gcc-ar rcs ./core.a ./wiring_pulse.S.o
avr-gcc-ar rcs ./core.a ./WInterrupts.c.o
avr-gcc-ar rcs ./core.a ./hooks.c.o
avr-gcc-ar rcs ./core.a ./wiring.c.o
avr-gcc-ar rcs ./core.a ./wiring_analog.c.o
avr-gcc-ar rcs ./core.a ./wiring_digital.c.o
avr-gcc-ar rcs ./core.a ./wiring_pulse.c.o
avr-gcc-ar rcs ./core.a ./wiring_shift.c.o
avr-gcc-ar rcs ./core.a ./CDC.cpp.o
avr-gcc-ar rcs ./core.a ./HardwareSerial.cpp.o
avr-gcc-ar rcs ./core.a ./HardwareSerial0.cpp.o
avr-gcc-ar rcs ./core.a ./HardwareSerial1.cpp.o
avr-gcc-ar rcs ./core.a ./HardwareSerial2.cpp.o
avr-gcc-ar rcs ./core.a ./HardwareSerial3.cpp.o
avr-gcc-ar rcs ./core.a ./IPAddress.cpp.o
avr-gcc-ar rcs ./core.a ./PluggableUSB.cpp.o
avr-gcc-ar rcs ./core.a ./Print.cpp.o
avr-gcc-ar rcs ./core.a ./Stream.cpp.o
avr-gcc-ar rcs ./core.a ./Tone.cpp.o
avr-gcc-ar rcs ./core.a ./USBCore.cpp.o
avr-gcc-ar rcs ./core.a ./WMath.cpp.o
avr-gcc-ar rcs ./core.a ./WString.cpp.o
avr-gcc-ar rcs ./core.a ./abi.cpp.o
avr-gcc-ar rcs ./core.a ./main.cpp.o
avr-gcc-ar rcs ./core.a ./new.cpp.o




avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo -I../libraries/Keyboard/src -I../arduino/avr/libraries/HID/src -I../libraries/Mouse/src ../libraries/Keyboard/src/Keyboard.cpp -o Keyboard.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo -I../libraries/Keyboard/src -I../arduino/avr/libraries/HID/src -I../libraries/Mouse/src ../arduino/avr/libraries/HID/src/HID.cpp -o HID.cpp.o
avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo -I../libraries/Keyboard/src -I../arduino/avr/libraries/HID/src -I../libraries/Mouse/src ../libraries/Mouse/src/Mouse.cpp -o Mouse.cpp.o

avr-gcc-ar rcs ../ArduinoKeyboardHIDMousecore.a ./Keyboard.cpp.o
avr-gcc-ar rcs ../ArduinoKeyboardHIDMousecore.a ./HID.cpp.o
avr-gcc-ar rcs ../ArduinoKeyboardHIDMousecore.a ./Mouse.cpp.o

#Archivio il core (caching) compilato in: /tmp/arduino_cache_262524/core/core_arduino_avr_leonardo_d83e277ff62131de25c9da3fe73d86ec.a
#Linking everything together...

avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\"" -I../arduino/avr/cores/arduino -I../arduino/avr/variants/leonardo -I../libraries/Keyboard/src -I../libraries/HID/src -I../libraries/Mouse/src ../src/main.cpp -o main.o
avr-gcc -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4 -o main.elf main.o ../ArduinoKeyboardHIDMousecore.a -lm

#avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 main.elf main.eep
avr-objcopy -O ihex -R .eeprom main.elf main.hex

FILE_HEX=main.hex

avrdude -Cavrdude.conf -v -patmega32u4 -cusbasp -Pusb -U flash:w:${FILE_HEX}:i




avr-size -A main.elf
