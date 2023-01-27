
#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

//-----------------------------memcmp test------------------------------

START_TEST(s21_memcmp_test_1) {
  ck_assert_int_eq(memcmp("1234567890", "1234567890", 5),
                   s21_memcmp("1234567890", "1234567890", 5));
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  ck_assert_int_eq(memcmp("234567890", "2341", 0),
                   s21_memcmp("234567890", "2341", 0));
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  ck_assert_int_eq(memcmp("f", "f", 2), s21_memcmp("f", "f", 2));
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  ck_assert_int_eq(memcmp("", "", 1), s21_memcmp("", "", 1));
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  ck_assert_int_eq(memcmp("1234", "13", 2), s21_memcmp("1234", "13", 2));
}
END_TEST

//-----------------------------strncmp test-----------------------------

START_TEST(s21_strncmp_test_1) {
  ck_assert_int_eq(strncmp("1234567890", "1234567890", 5),
                   s21_strncmp("1234567890", "1234567890", 5));
}
END_TEST

START_TEST(s21_strncmp_test_2) {
  ck_assert_int_eq(strncmp("234567890", "2341", 0),
                   s21_strncmp("234567890", "2341", 0));
}
END_TEST

START_TEST(s21_strncmp_test_3) {
  ck_assert_int_eq(strncmp("1234567890", "", 1),
                   s21_strncmp("1234567890", "", 1));
}
END_TEST

START_TEST(s21_strncmp_test_4) {
  ck_assert_int_eq(strncmp("", "", 1), s21_strncmp("", "", 1));
}
END_TEST

START_TEST(s21_strncmp_test_5) {
  ck_assert_int_eq(strncmp("", "123", 3), s21_strncmp("", "123", 3));
}
END_TEST

//-----------------------------strcmp test-----------------------------

START_TEST(s21_strcmp_test_1) {
  ck_assert_int_eq(strcmp("1234567890", "1234567890"),
                   s21_strcmp("1234567890", "1234567890"));
}
END_TEST

START_TEST(s21_strcmp_test_2) {
  ck_assert_int_eq(strcmp("1234567890", ""), s21_strcmp("1234567890", ""));
}
END_TEST

START_TEST(s21_strcmp_test_3) {
  ck_assert_int_eq(strcmp("", ""), s21_strcmp("", ""));
}
END_TEST

START_TEST(s21_strcmp_test_4) {
  ck_assert_int_eq(strcmp("", "123"), s21_strcmp("", "123"));
}
END_TEST

START_TEST(s21_strcmp_test_5) {
  ck_assert_int_eq(strcmp("222", ""), s21_strcmp("222", ""));
}
END_TEST

//-----------------------------strcspn test-----------------------------

START_TEST(s21_strcspn_test_1) {
  ck_assert_uint_eq(strcspn("1234567890", "321"),
                    s21_strcspn("1234567890", "321"));
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  ck_assert_uint_eq(strcspn("1234567890", "234"),
                    s21_strcspn("1234567890", "234"));
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  ck_assert_uint_eq(strcspn("1234567890", ""), s21_strcspn("1234567890", ""));
}
END_TEST

START_TEST(s21_strcspn_test_4) {
  ck_assert_uint_eq(strcspn("", "123"), s21_strcspn("", "123"));
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  ck_assert_uint_eq(strcspn("", ""), s21_strcspn("", ""));
}
END_TEST

//-----------------------------strlen test-----------------------------

START_TEST(s21_strlen_test_1) {
  ck_assert_uint_eq(strlen("asdap"), s21_strlen("asdap"));
}
END_TEST

START_TEST(s21_strlen_test_2) {
  ck_assert_uint_eq(strlen("sadlkjfhalskjdfhlkajsdhflkasjdfh"),
                    s21_strlen("sadlkjfhalskjdfhlkajsdhflkasjdfh"));
}
END_TEST

START_TEST(s21_strlen_test_3) { ck_assert_uint_eq(strlen(""), s21_strlen("")); }
END_TEST

START_TEST(s21_strlen_test_4) {
  ck_assert_uint_eq(strlen("hi\0there"), s21_strlen("hi\0there"));
}
END_TEST

//-----------------------------strspn test-----------------------------

START_TEST(s21_strspn_test_1) {
  ck_assert_uint_eq(strspn("1234567890", "321"),
                    s21_strspn("1234567890", "321"));
}
END_TEST

START_TEST(s21_strspn_test_2) {
  ck_assert_uint_eq(strspn("1234567890", "234"),
                    s21_strspn("1234567890", "234"));
}
END_TEST

START_TEST(s21_strspn_test_3) {
  ck_assert_uint_eq(strspn("1234567890", ""), s21_strspn("1234567890", ""));
}
END_TEST

START_TEST(s21_strspn_test_4) {
  ck_assert_uint_eq(strspn("", "123"), s21_strspn("", "123"));
}
END_TEST

START_TEST(s21_strspn_test_5) {
  ck_assert_uint_eq(strspn("", ""), s21_strspn("", ""));
}
END_TEST

//-----------------------------tests end-----------------------------

Suite *s21_string_suite(void) {
  Suite *test_lib;
  TCase *test_case_core;

  test_lib = suite_create("test s21_strlen.h");
  test_case_core = tcase_create("Core");

  tcase_add_test(test_case_core, s21_memcmp_test_1);
  tcase_add_test(test_case_core, s21_memcmp_test_2);
  tcase_add_test(test_case_core, s21_memcmp_test_3);
  tcase_add_test(test_case_core, s21_memcmp_test_4);
  tcase_add_test(test_case_core, s21_memcmp_test_5);

  tcase_add_test(test_case_core, s21_strncmp_test_1);
  tcase_add_test(test_case_core, s21_strncmp_test_2);
  tcase_add_test(test_case_core, s21_strncmp_test_3);
  tcase_add_test(test_case_core, s21_strncmp_test_4);
  tcase_add_test(test_case_core, s21_strncmp_test_5);

  tcase_add_test(test_case_core, s21_strcmp_test_1);
  tcase_add_test(test_case_core, s21_strcmp_test_2);
  tcase_add_test(test_case_core, s21_strcmp_test_3);
  tcase_add_test(test_case_core, s21_strcmp_test_4);
  tcase_add_test(test_case_core, s21_strcmp_test_5);

  tcase_add_test(test_case_core, s21_strcspn_test_1);
  tcase_add_test(test_case_core, s21_strcspn_test_2);
  tcase_add_test(test_case_core, s21_strcspn_test_3);
  tcase_add_test(test_case_core, s21_strcspn_test_4);
  tcase_add_test(test_case_core, s21_strcspn_test_5);

  tcase_add_test(test_case_core, s21_strlen_test_1);
  tcase_add_test(test_case_core, s21_strlen_test_2);
  tcase_add_test(test_case_core, s21_strlen_test_3);
  tcase_add_test(test_case_core, s21_strlen_test_4);

  tcase_add_test(test_case_core, s21_strspn_test_1);
  tcase_add_test(test_case_core, s21_strspn_test_2);
  tcase_add_test(test_case_core, s21_strspn_test_3);
  tcase_add_test(test_case_core, s21_strspn_test_4);
  tcase_add_test(test_case_core, s21_strspn_test_5);

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