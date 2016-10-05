ECHO ON
del -f *.gcda *.gcno *.gcov

mingw32-make clean -f makefile_gcov
mingw32-make -f makefile_gcov

main.exe
main.exe notexist.txt notexistans.txt
main.exe tests/1.txt tests/answer1.txt
main.exe tests/1.txt tests/blocked.txt
main.exe tests/3.txt tests/answer3.txt
main.exe tests/empty.txt tests/answer_empty.txt
main.exe tests/full.txt tests/answer_full.txt
main.exe tests/nomoreaver.txt tests/answer_nomoreaver.txt

gcov main.exe
PAUSE