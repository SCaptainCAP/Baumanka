rm -f *.gcda *.gcno *.gcov

main
main notexist.txt
main tests/1.txt
main tests/2.txt
main tests/empty.txt

gcov main
