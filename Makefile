CC=gcc
CFLAGS=-I.
DEPS = io.h boundaries.h integration.h memory.h
OBJ = io.o boundaries.o integration.o memory.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)