.PHONY : all, clean, style, re, test, s21_string.a, tests_c, cov_objs, \
		 test_bins, gcov_report, verter
# compilation options
CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11
LDFLAGS = # will be set based on OS
# paths
SRC := ../src# ../ is used for the reasons of convenience and consistency
OBJ := ../obj
TST := tests
BIN := $(TST)/build
CRP := coverage_report
# project files
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CHECKS := $(wildcard $(TST)/*.check)
TESTSC := $(CHECKS:.check=.c)
TNAMES := $(shell basename -a $(CHECKS:%.check=%))
# platform dependent stuff
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	LDFLAGS = -lcheck
	ifeq ($(shell uname -p), arm) # M1+ Mac
		LDFLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include \
		      	  -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
	endif
else ifeq ($(OS),Linux)
	LDFLAGS = -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif
# shell macros
MK := mkdir -p
RM := rm -rf

all: s21_string.a

clean:
	$(RM) *.{out,o,a,gcda,gcno,gcov,html,css}
	$(RM) $(BIN)
	$(RM) $(CRP)
	$(RM) $(OBJ)
	$(RM) $(TST)/*.c

re: clean all

style:
	clang-format -style=Google -i *.[ch]

s21_string.a:
	$(MK) $(OBJ)
	cd $(OBJ) && $(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)/*.c
	ar rsc $@ $(OBJ)/*
	ranlib $@

test: tests_c cov_objs test_bins gcov_report

tests_c: $(TESTSC)
%.c: %.check
	checkmk clean_mode=1 $< > $@
cov_objs:
	$(MK) $(OBJ)
	$(MAKE) $(OBJS)
s21_%.o: s21_%.c
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -c -o $(OBJ)/$@ $<
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $(OBJ)/$*_test.o $(TST)/$*_test.c 2>/dev/null || true
test_bins:
	$(MK) $(BIN)
	$(MAKE) $(TNAMES)
%_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_$*.o
# functions that have dependencies on other functions:
#strcspn_test:#                               |test_exe |test_o     |function_o          |dependent_functions_o
#	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_strcspn.o $(OBJ)/s21_strlen.o
memchr_test:
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/s21_memchr.o
gcov_report:
	$(MK) $(CRP)
	$(foreach file, $(TNAMES), $(BIN)/$(file);)
	gcovr --html-details --html-self-contained -o $(CRP)/report.html $(OBJ)
	open $(CRP)/report.html
	$(RM) $(OBJ)/*.{gcno,gcda}

verter:
	cd ../materials/build && bash run.sh
