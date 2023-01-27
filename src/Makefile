.PHONY : all, clean, style, re, test, s21_string.a, tests_c, objs, test_bins, report

CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11 -O2
RM := rm -f
OS := $(shell uname -s)
SRC := .
OBJ := ../obj
TST := ./tests
BIN := ../build
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CHECKS = $(wildcard $(TST)/*.check)
TESTSC = $(CHECKS:.check=.c)
TNAMES = $(shell basename $(CHECKS:%.check=%))
ifeq ($(OS), Darwin)
	LDFLAGS = -lcheck
	ifeq ($(shell uname -p), arm)
		LDFLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include \
		      	  -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
	endif
else ifeq ($(OS),Linux)
	LDFLAGS = -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif


all: s21_string.a test

clean:
	$(RM) *.{out,o,a,gcda,gcno,gcov,html,css}
	$(RM) $(TST)/*.c
	$(RM) $(OBJ)/*
	$(RM) $(BIN)/*

re: clean all

style:
	clang-format -style=Google -i *.[ch]

s21_string.a: s21_string.c
	ar rsc $@ $(OBJ)/s21_*
	ranlib $@

test: clean tests_c objs test_bins report

tests_c: $(TESTSC)
%.c: %.check
	checkmk clean_mode=1 $< > $@
objs: $(OBJS)
s21_%.o: s21_%.c
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -c -o $(OBJ)/$@ $<
	-$(CC) $(CFLAGS) $(LDFLAGS) -c -o $(OBJ)/$*_test.o $(TST)/$*_test.c 2>/dev/null
test_bins: $(TNAMES)
%_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_$*.o
# functions that have dependencies on other functions:
strcspn_test:#                               |test_exe |test_o     |function_o          |dependent_functions
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_strcspn.o $(OBJ)/s21_strlen.o
strspn_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_strspn.o $(OBJ)/s21_strlen.o

report:
	$(foreach file, $(TNAMES), $(BIN)/$(file);)
	mv $(OBJ)/*.{gcno,gcda} .
	gcovr -r . --html -o report.html
	open report.html
	$(RM) *.{gcno,gcda}
