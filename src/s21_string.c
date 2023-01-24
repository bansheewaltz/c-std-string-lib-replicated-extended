#include "s21_string.h"

#include <stdio.h>
#include <string.h>

s21_size_t s21_strlen(const char *s) {
  s21_size_t result = 0;
  while ((s + result) != s21_NULL) {
    result++;
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0, fend = 0;
  const unsigned char *pstr1 = (unsigned char *)str1,
                      *pstr2 = (unsigned char *)str2;
  while (n-- && fend == 0) {
    if (*pstr1 != *pstr2) {
      result = ((*pstr1 < *pstr2) ? -1 : 1);
      fend = 1;
    } else {
      pstr1++;
      pstr2++;
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const unsigned char *pstr1 = (unsigned char *)str1,
                      *pstr2 = (unsigned char *)str2;
  int result = 0, fend = 0;
  while ((--n != 0) && fend == 0) {
    if (*pstr1 != *pstr2) {
      result = (unsigned char)*pstr1 - (unsigned char)*pstr2;
      fend = 1;
    } else {
      pstr1++;
      pstr2++;
    }
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0, fend = 0;
  while (fend == 0) {
    if (*str1 == *str2) {
      str1++;
      str2++;
      if (*str1 == '\0') {
        result = 0;
        fend = 1;
      }
    } else {
      result = (unsigned char)*str1 - (unsigned char)*str2;
      fend = 1;
    }
  }
  return result;
}