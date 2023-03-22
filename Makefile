CFLAGS = -nostdlib -mmcu=atmega328p #-ffunction-sections -fdata-sections #-Wl,--gc-sections
LDFLAGS = 

obj: m328p.s 
	avr-gcc $(CFLAGS) -c m328p.s *.s *.c

elf: m328p.ld obj
	avr-gcc $(CFLAGS) $(LDFLAGS) -T m328p.ld *.o -o code.elf -O3 # -Wl,--verbose 

dasm: elf
	avr-objdump code.elf -D 

bin: elf
	avr-objcopy -O binary code.elf code.bin && xxd code.bin

hex: elf
	avr-objcopy -O ihex code.elf code.hex

install: hex m328p.fuses
	minipro -p "ATMEGA328P@TQFP32" -i -c config -w m328p.fuses	# Set the fuses
	minipro -p "ATMEGA328P@TQFP32" -i -f ihex -c code -w code.hex --skip_verify # Write the code to flash

all: bin

clean: 
	rm *.o code.*
