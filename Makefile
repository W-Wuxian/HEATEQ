#-ffpe-trap=invalid,zero,overflow,underflow,inexact,denormal
CC=gcc
INTTYPE=-DDEF_INT64=1 -DTEST
DEBUG=-Wall -fbounds-check -pedantic  -g3
COMPILE=$(CC) $(DEBUG) $(INTTYPE)
EXECNAME=C-SEQ-FDM

help:
	@echo "COMPILE is set to $(COMPILE)"

all: main.o
	$(COMPILE) -o $(EXECNAME) main.c -I ./def
	@echo COMPILATION DONE

run:
	./$(EXECNAME)

clean:
	rm *.o $(EXECNAME)