# Makefile author: dondarri | dondarri@student.21-school.ru
CONFIG := release
### many variables are stored in a shared makefile
include Makefile.common
vpath %.c $(SRC) $(UTL)# sets search paths for .c files
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
endif

s21_string.a: $(OBJS)
	ar -rsc $@ $^

$(OBJ)/%.o: %.c $(HDRS)
	$(dir_guard)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: test gcov_report
test gcov_report: lib
ifeq ($(DEBUG), 1)
	$(MAKE) -f Makefile.unit_testing $@
endif
	@$(MAKE) -s -f Makefile.unit_testing $@

.PHONY: clean
clean:
	$(RM) $(BUILD)
	$(RM) $(REPORTS)
	$(RM) $(LIBNAME).a

.PHONY: re
re: clean
	$(MAKE) all



.PHONY: lib
lib: libs21_string.a
libs21_string.a: s21_string.a
	$(MK) $(LIB)
	cp $< $(LIB)/$@

.PHONY: memcheck
memcheck: lib
ifeq (, $(shell which valgrind))
	$(error "valgrind" should be installed)
endif
ifeq ($(DEBUG), 1)
	$(MAKE) -f Makefile.memcheck $@
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

.PHONY: brew
brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh