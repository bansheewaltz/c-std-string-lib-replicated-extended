.PHONY : all, clean, test, s21_string.a, gcov_report, check, re, checkmk

CC := gcc -Wall -Werror -Wextra
RM := rm -f
OS := $(shell uname -s)
SRC := .
OBJ := ../obj
TST := ../tests
CHECKS = $(wildcard $(TST)/*.check)
UTESTS = $(CHECKS:.check=.c)
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o) $(CHECKS:.check=.o)
TNAMES = $(shell basename $(CHECKS:%.check=%))
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
	$(RM) *.{out,o,gcda,gcno,gcov,html,css}
	$(RM) $(TST)/*.{c,o,gcno,gcda}
	$(RM) $(OBJ)/*

re: clean all

style:
	clang-format -style=Google -i *.c *.h

s21_string.a: s21_string.c
	$(CC) -c -o s21_string.o s21_string.c
	ar rsc s21_string.a s21_string.o
	ranlib s21_string.a
	rm *.o

sample1: clean checkmk
	$(CC) $(OS_FLAGS) --coverage -c -o s21_strlen.o s21_strlen.c
	$(CC) $(OS_FLAGS) -c -o strlen_test.o ../tests/strlen_test.c
	$(CC) $(OS_FLAGS) --coverage strlen_test.o s21_strlen.o
	./a.out
	gcov -f *.gcno
	gcovr -r . --html -o report.html
	open report.html

sample2: clean checkmk
	$(CC) $(OS_FLAGS) --coverage -c -o s21_strlen.o s21_strlen.c
	$(CC) $(OS_FLAGS) --coverage -c -o s21_memcpy.o s21_memcpy.c
	$(CC) $(OS_FLAGS) -c -o strlen_test.o ../tests/strlen_test.c
	$(CC) $(OS_FLAGS) -c -o memcpy_test.o ../tests/memcpy_test.c
	$(CC) $(OS_FLAGS) --coverage -o strlen strlen_test.o s21_strlen.o
	$(CC) $(OS_FLAGS) --coverage -o memcpy memcpy_test.o s21_memcpy.o
	./strlen
	./memcpy
	gcov -f *.gcno
	gcovr -r . --html -o report.html
	open report.html

test: clean checkmk obj move bin gcov

checkmk: $(UTESTS)
%.c: %.check
	checkmk clean_mode=1 $< > $@
obj: $(OBJS)
%_test.o: %.c
	$(CC) $(OS_FLAGS) -c -o $@ $<
%.o: %.c
	$(CC) $(OS_FLAGS) --coverage -c -o $(OBJ)/$@ $<
move:
	mv $(TST)/*.o $(OBJ)
bin: $(TNAMES)
%_test:
	$(CC) $(OS_FLAGS) --coverage -o $(OBJ)/$@ $(OBJ)/$@.o $(OBJ)/s21_$*.o
	$(OBJ)/$@
# functions that has dependencies on other functions
strcspn_test:#                      |test_exe |test_o     |testing_function    |dependency
	$(CC) $(OS_FLAGS) --coverage -o $(OBJ)/$@ $(OBJ)/$@.o $(OBJ)/s21_strcspn.o $(OBJ)/s21_strlen.o
	$(OBJ)/$@
strspn_test:
	$(CC) $(OS_FLAGS) --coverage -o $(OBJ)/$@ $(OBJ)/$@.o $(OBJ)/s21_strspn.o $(OBJ)/s21_strlen.o
	$(OBJ)/$@

gcov:
	cd $(OBJ) && gcov -f *.gcno
	cd $(OBJ) && gcovr -r ../src --html -o report.html
	open $(OBJ)/report.html
