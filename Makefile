CC=gcc
CFLAGS=-I.

ODIR=obj

LIBS=-lm

DEPS = io.h boundaries.h integration.h memory.h

_OBJ = io.o boundaries.o integration.o memory.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)