#-ffpe-trap=invalid,zero,overflow,underflow,inexact,denormal
CC=gcc
INTTYPE=-DDEF_INT64=1 -DTEST
DEBUG=-Wall -fbounds-check -pedantic -g3 -DDEF_INT64=1
EXT=
COMPILE=$(CC) $(DEBUG) $(EXT) $(INTTYPE)
EXECNAME=C-SEQ-FDM

help:
	@echo "COMPILE is set to $(COMPILE)"

all: main.o
	$(COMPILE) -o $(EXECNAME) main.c
	@echo COMPILATION DONE

run:
	./$(EXECNAME)

clean:
	rm *.o $(EXECNAME)