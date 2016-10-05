greeting.exe : main.o
	gcc -o main main.o
	
main.o : main.c
	gcc -std=c99 -Wall -Werror -pedantic -c hello.c
	
clean :
	rm *.o main
