
#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_strlen_test_1) {}
END_TEST

Suite *s21_string_suite(void) {
  Suite *test_lib;
  TCase *test_case_core;

  test_lib = suite_create("test s21_strlen.h");
  test_case_core = tcase_create("Core");

  tcase_add_test(test_case_core, s21_strlen_test_1);

  suite_add_tcase(test_lib, test_case_core);
  return test_lib;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  s = s21_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  s = NULL;
  sr = NULL;
}