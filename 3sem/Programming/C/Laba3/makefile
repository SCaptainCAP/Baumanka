CC := mingw32-gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJS := realization.o main.o

main.exe : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o main.exe

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS) main.exe
