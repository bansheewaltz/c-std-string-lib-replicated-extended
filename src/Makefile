CONFIG := release
### many variables are stored in a shared makefile
include Makefile.common
vpath %.c $(SRC) $(UTL)# sets search paths for .c files
vpath lib%.a $(LIB)
export


.PHONY: all
all:
	$(MAKE) lib
	$(MAKE) test
	$(MAKE) gcov_report
ifeq ($(KERNEL), Linux)
	$(MAKE) memcheck
endif

s21_string.a: $(OBJS)
	ar -rsc $@ $^

$(OBJ)/%.o: %.c $(HDRS)
	$(dir_guard)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(BUILD)
	$(RM) $(REPORTS)
	$(RM) $(LIBNAME).a

.PHONY: test gcov_report
test gcov_report: lib
ifeq ($(DEBUG), 1)
	$(MAKE) -f Makefile.unit_testing $@
endif
	@$(MAKE) -s -f Makefile.unit_testing $@



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
	$(MAKE) -s -f Makefile.memcheck $@

.PHONY: miniverter
miniverter: clean
	cd $(SCRIPTS) && bash run_miniverter.sh

.PHONY: re
re: clean
	$(MAKE) all

.PHONY: linter
linter:
	clang-format -style=Google -i $(shell find . -type f -name '*.h' -o -name '*.c' -o -name '*.cs')
.PHONY: linter_check
linter_check:
	clang-format -style=Google -n $(shell find . -type f -name '*.h' -o -name '*.c' -o -name '*.cs')

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