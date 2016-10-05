CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJS := fileanalyzer.o matfunc.o

main : $(OBJS) main.o
	$(CC) $^ -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -c $<
	
clean :
	rm *.o main
