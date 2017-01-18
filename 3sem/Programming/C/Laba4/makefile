CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -g3 -O0 -fprofile-arcs -ftest-coverage
OBJS := realization.o

all : main

main : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o main

test : $(OBJS) test.o
	$(CC) $(CFLAGS) $^ -o test

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS) main test
