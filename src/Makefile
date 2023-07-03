# Makefile author: dondarri@student.21-school.ru
CONFIG ?= debug
### many variables are stored in a shared makefile
include Makefile.common
# build parameters
ifeq ($(CONFIG), debug)
	DBGFLAGS := -g
	CFLAGS := $(DBGFLAGS) $(WFLAGS) $(STDFLAG) $(INCFLAGS)
else
	CFLAGS := $(WFLAGS) $(STDFLAG) $(INCFLAGS)
endif
ifeq ($(OS), Alpine)
	CFLAGS := $(DBGFLAGS) $(INCFLAGS)
endif
# Makefile search paths
vpath %.c $(SRC) $(UTL)
vpath lib%.a $(LIB)
export


.PHONY: all
all:
ifeq ($(OS), )
	$(warning warning: it looks like this Makefile is not fully adapted to your OS)
endif
	$(MAKE) lib
ifneq ($(shell pkg-config --libs check 2> /dev/null), )
	$(MAKE) test
ifneq ($(shell which gcovr 2> /dev/null), )
	$(MAKE) gcov_report
endif
ifneq ($(shell which valgrind), )
	$(MAKE) memcheck
endif
endif

x_string.a: $(OBJS)
	ar -rsc $@ $^

$(OBJ)/%.o: %.c $(HDRS)
	$(dir_guard)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: test gcov_report
test gcov_report: lib
	@$(MAKE) -s -f Makefile.unit_testing $@

.PHONY: clean
clean:
	$(RM) $(BUILD)
	$(RM) $(REPORTS)
	$(RM) $(LIBNAME).a
	$(RM) *.out*

.PHONY: re
re: clean
	$(MAKE) all



.PHONY: lib
lib: libx_string.a
libx_string.a: x_string.a
	$(MK) $(LIB)
	cp $< $(LIB)/$@

.PHONY: memcheck
memcheck: lib
ifeq (, $(shell which valgrind))
	$(error "valgrind" should be installed)
endif
	@$(MAKE) -s -f Makefile.memcheck $@

.PHONY: linter linter_check
linter_check: LINTFLAG := -n
linter linter_check:
	$(LINT) $(LINTFLAG) $(shell find . -type f -name '*.h' -o -name '*.c')

.PHONY: miniverter
miniverter: clean
	cd $(SCRIPTS) && bash run_miniverter_test.sh

.PHONY: container
container:
ifeq (, $(shell which docker))
	$(error "Docker" should be installed)
endif
	$(MAKE) clean_build
	bash $(SCRIPTS)/run_docker_image.sh

.PHONY: test1
test1: x_string.a test
	@$(MAKE) -s -f Makefile.memcheck $@

.PHONY: brew
brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

# testf:
# 	gcc -g $(WFLAGS) $(INCFLAGS) lib/x_sprintf.c $(LDFLAGS) $(LDLIBS)
# 	./a.out
