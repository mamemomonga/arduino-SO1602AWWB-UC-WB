# ---------------------------------------------------

# シリアルポート
AR_PORT=/dev/cu.usbserial-221140

# スケッチ
AR_SKETCH=app

# Arduino UNO
# AR_FQBN=arduino:avr:uno

# Arduino Pro Mini/Micro
# AR_FQBN=arduino:avr:pro

# Arduino Nano Every
# AR_FQBN=arduino:megaavr:nona4809

# MiniCore 328
# AR_FQBN=MiniCore:avr:328

# mamemo 0002-AVR ATmega328PB,Bootloader
AR_FQBN=MiniCore:avr:328:bootloader=uart0,variant=modelPB,clock=16MHz_external

# ---------------------------------------------------

upload: build/$(AR_SKETCH).ino.hex
	arduino-cli upload -b $(AR_FQBN) -p $(AR_PORT) --input-dir "$(CURDIR)/build"

compile: build/$(AR_SKETCH).ino.hex

serial:
	screen $(AR_PORT)

clean:
	rm -rf build

build/$(AR_SKETCH).ino.hex: $(AR_SKETCH)/$(AR_SKETCH).ino
	arduino-cli compile -b $(AR_FQBN) --build-path "$(CURDIR)/build" $(AR_SKETCH)

.PHONY: upload compile serial clean