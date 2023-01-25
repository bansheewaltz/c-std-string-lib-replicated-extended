.PHONY : all, clean, test, s21_string.a, gcov_report, check, re, checkmk

CC = gcc -Wall -Werror -Wextra
OS = $(shell uname -s)
TEST_CHECK = $(wildcard testing/*.check)
TEST_C = $(TEST_CHECK:.check=.c)
ifeq ($(OS), Darwin)
	OS_FLAGS = -lcheck
	ifeq ($(shell uname -p), arm)
		OS_FLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include \
		           -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
	endif
else ifeq ($(OS),Linux)
	OS_FLAGS = -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif

all: s21_string.a test gcov_report

clean:
	rm -f *.{a,gcda,gcno,gcov,html,css} unit_test testing/*.c

re: clean all

check:
	clang-format -style=Google -i *.c *.h


s21_string.a : s21_string.c
	$(CC) -c -o s21_string.o s21_string.c
	ar rsc s21_string.a s21_string.o
	ranlib s21_string.a
	rm *.o

checkmk: $(TEST_C)
%.c: %.check
	checkmk clean_mode=1 $< > $@

test: clean checkmk
	$(CC) --coverage s21_string.c unittest.c -o unit_test $(OS_FLAGS)
	./unit_test

gcov_report: test
	./unit_test
	gcov -f *.gcno
	gcovr -r . --html -o report.html
	rm -f *.gcno *.gcda
