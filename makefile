CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=good better

all: $(PROGS)

good: good.o
	$(CC) $(CFLAGS) -o $@ $^

good.o: good.c
	$(CC) $(CFLAGS) -c $^

better: better.o
	$(CC) $(CFLAGS) -o $@ $^

better.o: better.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(PROGS) *.o *~ *.pyc
