CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAG= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32f411.ld -Wl,-Map=final.map
LDFLAG_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32f411.ld -Wl,-Map=final.map

all: main.o led.o stm32f411_startup.o syscalls.o final.elf 

semi: main.o led.o stm32f411_startup.o final_sh.elf

main.o: main.c 
	$(CC) $(CFLAGS) $^ -o $@

led.o: led.c 
	$(CC) $(CFLAGS) $^ -o $@

stm32f411_startup.o: stm32f411_startup.c
	$(CC) $(CFLAGS) $^ -o $@

syscalls.o: syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o led.o stm32f411_startup.o syscalls.o
	$(CC) $(LDFLAG) -o $@ $^

final_sh.elf: main.o led.o stm32f411_startup.o 
	$(CC) $(LDFLAG_SH) -o $@ $^

flash:
	openocd -f board/stm32f4discovery.cfg

clean:
	rm -rf *.o *.elf
