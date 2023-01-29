
#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

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
//-----------------------------s21_memchr test-----------------------------

START_TEST(s21_memchr_test_1) {
  ck_assert_pstr_eq(memchr("1234567890", '5', 7),
                    s21_memchr("1234567890", '5', 7));
}
END_TEST

START_TEST(s21_memchr_test_2) {
  ck_assert_pstr_eq(memchr("1234567890", '9', 7),
                    s21_memchr("1234567890", '9', 7));
}
END_TEST

START_TEST(s21_memchr_test_3) {
  ck_assert_pstr_eq(memchr("1234567890", '1', 7),
                    s21_memchr("1234567890", '1', 7));
}
END_TEST

//-----------------------------s21_strchr test-----------------------------

START_TEST(s21_strchr_test_1) {
  ck_assert_pstr_eq(strchr("1234567890", '5'),
                    s21_strchr("1234567890", '5'));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  ck_assert_pstr_eq(strchr("1234", '8'),
                    s21_strchr("1234", '8'));
}
END_TEST

START_TEST(s21_strchr_test_3) {
  ck_assert_pstr_eq(strchr("1234567890", '1'),
                    s21_strchr("1234567890", '1'));
}
END_TEST
//-----------------------------s21_strrchr test-----------------------------

START_TEST(s21_strrchr_test_1) {
  ck_assert_pstr_eq(strchr("1534567890", '5'),
                    s21_strchr("1534567890", '5'));
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  ck_assert_pstr_eq(strchr("1834", '8'),
                    s21_strchr("1834", '8'));
}
END_TEST

START_TEST(s21_strrchr_test_3) {
  ck_assert_pstr_eq(strchr("234567890", '1'),
                    s21_strchr("234567890", '1'));
}
END_TEST
//-----------------------------s21_strstr test-----------------------------

START_TEST(s21_strstr_test_1) {
  ck_assert_pstr_eq(strstr("Hello my old friend", "old"),
                    s21_strstr("Hello my old friend", "old"));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  ck_assert_pstr_eq(strstr("1978 year i'm was 18", "8"),
                    s21_strstr("1978 year i'm was 18", "8"));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  ck_assert_pstr_eq(strstr("You love me???", "can"),
                    s21_strstr("You love me???", "can"));
}
END_TEST

//-----------------------------s21_strerror test-----------------------------

START_TEST(s21_strerror_test_1) {
  ck_assert_pstr_eq(strerror(0),
                    s21_strerror(0));
}
END_TEST

START_TEST(s21_strerror_test_2) {
  ck_assert_pstr_eq(strerror(1),
                    s21_strerror(1));
}
END_TEST

START_TEST(s21_strerror_test_3) {
  ck_assert_pstr_eq(strerror(2),
                    s21_strerror(2));
}
END_TEST

//-----------------------------tests end-----------------------------

Suite *s21_string_suite(void) {
  Suite *test_lib;
  TCase *test_case_core;

  test_lib = suite_create("test s21_strlen.h");
  test_case_core = tcase_create("Core");

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

  tcase_add_test(test_case_core, s21_memchr_test_1);
  tcase_add_test(test_case_core, s21_memchr_test_2);
  tcase_add_test(test_case_core, s21_memchr_test_3);

  tcase_add_test(test_case_core, s21_strchr_test_1);
  tcase_add_test(test_case_core, s21_strchr_test_2);
  tcase_add_test(test_case_core, s21_strchr_test_3);

  tcase_add_test(test_case_core, s21_strrchr_test_1);
  tcase_add_test(test_case_core, s21_strrchr_test_2);
  tcase_add_test(test_case_core, s21_strrchr_test_3);

  tcase_add_test(test_case_core, s21_strstr_test_1);
  tcase_add_test(test_case_core, s21_strstr_test_2);
  tcase_add_test(test_case_core, s21_strstr_test_3);

  tcase_add_test(test_case_core, s21_strerror_test_1);
  tcase_add_test(test_case_core, s21_strerror_test_2);
  tcase_add_test(test_case_core, s21_strerror_test_3);
  

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