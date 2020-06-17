tests : test/bin/handrolled_tests test/bin/cunit_tests

test/bin/handrolled_tests: handrolled_tests.c hash_table.c hash_table.h
	mkdir -p test/bin
	gcc -std=c99 -Wpedantic -o test/bin/handrolled_tests handrolled_tests.c hash_table.c

test/bin/cunit_tests: cunit_tests.c hash_table.c hash_table.h
	mkdir -p test/bin
	gcc -std=c99 -Wpedantic -o test/bin/cunit_tests cunit_tests.c hash_table.c -lcunit