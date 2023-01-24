.PHONY : all, clean, test, s21_string.a, gcov_report, check

CC = gcc -Wall -Werror -Wextra
OS = $(shell uname -s)
ifeq ($(OS), Darwin)
OS_FLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
# OS_FLAGS = -lcheck
endif
ifeq ($(OS),Linux)
OS_FLAGS = -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif

all: s21_string.a test gcov_report

clean:
	rm *.a *.gcda *.gcno *.html unit_test

check:
	clang-format -style=Google -i *.c *.h


s21_string.a : s21_string.c
	$(CC) -c -o s21_string.o s21_string.c
	ar rsc s21_string.a s21_string.o
	ranlib s21_string.a
	rm *.o

test: 
	$(CC) --coverage s21_string.c unittest.c -o unit_test $(OS_FLAGS)
	./unit_test

gcov_report: test
	./unit_test
	gcov -f *.gcno
	gcovr -r . --html -o report.html