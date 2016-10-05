greeting.exe : main.o
	gcc -o main main.o
	
main.o : main.c
	gcc -std=c99 -Wall -Werror -pedantic -c -g3 main.c
	
clean :
	rm *.o main
