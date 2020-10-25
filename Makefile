SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/
EXESRC=$(wildcard exesrc/*c)
EXEOBJ=$(patsubst %c, %o, $(EXESRC))

CFLAGS=-I $(INC)
EXE=exe/app.elf

.SECONDARY:

all: $(EXE)

%.elf: $(OBJ) $(EXEOBJ)
	gcc $(OBJ) $(EXEOBJ) -o $@ -lm

%.o: %.c
	gcc -c $< -I inc/ -o $@

clean:
	rm -f $(OBJ) $(EXE) $(EXEOBJ)


