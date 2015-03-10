CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=simple complex

all: $(PROGS)

simple: simple.o
	$(CC) $(CFLAGS) -o $@ $^

simple.o: simple.c
	$(CC) $(CFLAGS) -c $^

complex: complex.o
	$(CC) $(CFLAGS) -o $@ $^

complex.o: complex.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(PROGS) *.o *~ *.pyc
