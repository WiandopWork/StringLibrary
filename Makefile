build: main.o string.o tests.o
	gcc main.o string.o tests.o -lm
	./a.exe

main.o: main.c
	gcc -c main.c

string.o: string.c string.h
	gcc -c string.c

tests.o: tests/tests.c tests/tests.h
	gcc -c tests/tests.c -o tests.o

clean: main.o string.o tests.o
	del a.exe main.o string.o tests.o

coverage_check: main.c string.c string.h tests/tests.c tests/tests.h
	gcc -c --coverage main.c
	gcc -c --coverage string.c
	gcc -c --coverage tests/tests.c

link_check: main.o string.o tests.o
	gcc --coverage main.o string.o tests.o -o check.exe

start_check: coverage_check link_check
	make coverage_check
	make link_check

	./check.exe

	gcov main.c -m -b
	gcov string.c -m -b
	gcov tests.c -m -b

	make clean_check

clean_check:
	del check.exe *.c.gcov *.gcda *.gcno
