CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=simple

all: $(PROGS)

simple: simple.o
	$(CC) $(CFLAGS) -o $@ $^

simple.o: simple.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(PROGS) *.o *~
