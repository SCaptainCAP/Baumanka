CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -g3
OBJS := long_number.o main.o

main : $(OBJS)
	$(CC) $^ -o main

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS) main
