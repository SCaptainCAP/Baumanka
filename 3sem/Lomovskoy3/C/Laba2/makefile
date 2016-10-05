CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -g3
OBJS := realization.o main.o

main : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o main

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS) main test
	rm -f *.gcda *.gcno *.gcov
