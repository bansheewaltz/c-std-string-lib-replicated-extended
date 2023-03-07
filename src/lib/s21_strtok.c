#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;
  char *token;
  int flag = 0;
  int flags = 0;
  if (str != s21_NULL) {
    next_token = str;
  } else {
    token = s21_NULL;
    flags++;
  }
  if (flags == 0) {
    while (*next_token && s21_strchr(delim, *next_token)) {
      next_token++;
    }

    if (*next_token == '\0') {
      token = s21_NULL;
      flag++;
    }

    if (flag == 0) {
      token = next_token;
      while (*next_token && !s21_strchr(delim, *next_token)) {
        next_token++;
      }

      if (*next_token == '\0') {
        next_token = s21_NULL;
      } else {
        *next_token = '\0';
        next_token++;
      }
    }
  }

  return token;
}