ECHO ON
del -f *.gcda *.gcno *.gcov

mingw32-make clean -f makefile_gcov
mingw32-make -f makefile_gcov

main.exe
main.exe notexist.txt
main.exe tests/1.txt
main.exe tests/2.txt
main.exe tests/empty.txt

gcov main.exe
PAUSE
