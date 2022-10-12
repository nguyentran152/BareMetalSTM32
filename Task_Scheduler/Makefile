PROGRAM=task_scheduler
OBJECTS=startup_stm32f411ve.o main.o
CC=arm-none-eabi-gcc

TARGET_FLAGS=\
	--specs=nosys.specs\
	-mcpu=cortex-m4\
	-mthumb\
	-mlittle-endian\
	-mfpu=fpv4-sp-d16\
	-mfloat-abi=hard\
	-mthumb-interwork
CFLAGS=\
	-g -Wall -Wextra -Werror\
	$(TARGET_FLAGS)\
	
LDFLAGS=\
	$(TARGET_FLAGS)\
	-Wl,-Tstm32f411ls.ld

%.o: %.s
	$(CC) -c -o $@ $<

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

clean: 
	rm *.o
	
flash: 
	openocd -f openocd.cfg -c "program $(PROGRAM) verify reset exit"

gdb:
	arm-none-eabi-gdb -q $(PROGRAM) -x gdb.cfg
	
.PHONY: clean flash gdb
