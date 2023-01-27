.PHONY : all, clean, test, s21_string.a, gcov_report, check, re, checkmk

CC := gcc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f
OS := $(shell uname -s)
SRC := .
OBJ := ../obj
TST := ./tests
BIN := ../build
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CHECKS = $(wildcard $(TST)/*.check)
UTESTS = $(CHECKS:.check=.c)
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
	$(RM) $(TST)/*.{c,o,gcno,gcda}
	$(RM) $(OBJ)/*
	$(RM) $(BIN)/*

re: clean all

style:
	clang-format -style=Google -i *.c *.h

s21_string.a: s21_string.c
	$(CC) -c -o s21_string.o s21_string.c
	ar rsc s21_string.a s21_string.o
	ranlib s21_string.a
	rm *.o

test: clean checkmk obj bin exe gcov

checkmk: $(UTESTS)
%.c: %.check
	checkmk clean_mode=1 $< > $@
obj: $(OBJS)
s21_%.o: s21_%.c
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -c -o $(OBJ)/$@ $<
	-$(CC) $(CFLAGS) $(LDFLAGS) -c -o $(OBJ)/$*_test.o $(TST)/$*_test.c 2>/dev/null
bin: $(TNAMES)
%_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_$*.o
# functions that has dependencies on other functions
strcspn_test:#                               |test_exe |test_o     |function_o          |dependent_functions
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_strcspn.o $(OBJ)/s21_strlen.o
strspn_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_strspn.o $(OBJ)/s21_strlen.o
exe:
	 $(foreach file, $(TNAMES), ../build/$(file);)

gcov:
	mv $(OBJ)/*.{gcno,gcda} .
	gcovr -r . --html -o report.html
	open report.html
	$(RM) *.{gcno,gcda}
