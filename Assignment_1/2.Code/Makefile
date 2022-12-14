#@copyright : Ahmed Maged

#Our Device
DEVICE=atmega32

CC=avr-gcc
#gcc
#arm none-eabi
CFLAGS= -Wall -gdwarf-2 

# The headers files needed for building the application ex -I<dir1> -I<dir2> !!!no space between I & dir!!! 
#--> dot "." means current directory ".." back one folder 
INCLUDE= -I.
#INCLUDE += -I../Math/
#INCLUDE += -I<dir2>


#If all Sources File in The Same Location 
SRC =$(wildcard *.c)

#else (src) in different locations 
#SRC = $(main).c
#SRC += src/file1.c
#SRC += src/file2.c

#For Generate .o File From .c
OBJ =$(SRC:.c=.o)

OBJCOPY = avr-objcopy
CCSIZE = avr-size

#optimizations Options {1, 2, 3(fastest), s(smallest), g(for debugging only)}
OPT = -Os
#For Generate Hex_File
HFLAGS = -j .text -j .data -O ihex

#My Project Name
project_name = 1_2
Firmware = firmware
all: $(Firmware).hex $(Firmware).elf size
	@echo "======== Build is Done By<Ahmed Maged> ========"
	
%.o:%.c
	$(CC) $(INCLUDE) $(OPT) $(CFLAGS) -mmcu=$(DEVICE) -c $< -o $@
	#avr-gcc.exe -I. -Os -Wall -gdwarf-2 -mmcu=atmega32 -c main.c -o main.o
	
$(Firmware).elf:$(OBJ)
	$(CC) $(INCLUDE) $(OPT) $(OBJ) -mmcu=$(DEVICE) -o $@
	#avr-gcc.exe -I. -Os main.o -mmcu=atmega32 -o hamada.elf
	
%.hex:%.elf
	$(OBJCOPY) $(HFLAGS) $< $@
	
size : $(Firmware).elf
	$(CCSIZE) --format=avr --mcu=$(DEVICE) $< 
	
clean_all:
	rm *.o *.elf *.hex
	@echo "Everything clean successfully"
	
clean:
	rm *.elf *.hex
	@echo "Clean Done Successfully"
	
	
	
	
	
	
	
	
	
	
#Note if src is not in the same location so i should give it to generator of .o like this 
#%.o:$(SRC)
#	$(CC) $^ $(INCLUDE) $(OPT) $(CFLAGS) -mmcu=$(DEVICE) -o $@


