CC=gcc
DEBUG=-Wall -ffpe-trap=invalid,zero,overflow,underflow,inexact,denormal -fbounds-check -pedantic  -g3
COMPILE=$(CC) $(DEBUG)
EXECNAME=C-SEQ-FDM

help:
	@echo "COMPILE is set to $(COMPILE)"

all: main.o
	$(COMPILE) -o $(EXECNAME) main.o
	@echo COMPILATION DONE

run:
	./$(EXECNAME)

clean:
	rm *.o $(EXECNAME)