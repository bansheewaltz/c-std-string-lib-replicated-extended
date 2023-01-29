#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i;
  while ((str[i] != '\0') && (str[i] != c)) i++;
  return c == str[i] ? (char *)str + i : NULL;
}