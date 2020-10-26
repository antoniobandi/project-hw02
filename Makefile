SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/
EXESRC=$(wildcard exesrc/*c)
EXEOBJ=$(patsubst %c, %o, $(EXESRC))

CFLAGS=-I $(INC)
EXE01=exe/test01.elf
EXE02=exe/test02.elf
EXE03=exe/test03.elf
EXE04=exe/test04.elf
EXE05=exe/test05.elf
EXE06=exe/test06.elf
EXE07=exe/test07.elf
EXEDFT=exe/test_dft.elf
EXEIDFT=exe/test_idft.elf

.SECONDARY:

run: all
	./$(EXE01) 
	./$(EXE02) 
	./$(EXE03)  
	./$(EXE04) 
	./$(EXE05) 
	./$(EXE06)
	./$(EXE07) 
	./$(EXEDFT) 
	./$(EXEIDFT)

all: $(EXE01) $(EXE02) $(EXE03) $(EXE04) $(EXE05) $(EXE06) $(EXE07) $(EXEDFT) $(EXEIDFT)

exe/%.elf: exesrc/%.o $(EXEOBJ) $(OBJ)
	gcc $< $(OBJ) -o $@ -lm

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXEOBJ) $(EXE01) $(EXE02) $(EXE03) $(EXE04) $(EXE05) $(EXE06) $(EXE07) $(EXEDFT) $(EXEIDFT) dft.txt test07.txt
