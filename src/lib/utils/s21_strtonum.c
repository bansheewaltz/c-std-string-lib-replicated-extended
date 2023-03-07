#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "s21_utils.h"

int char_value(char *symbol, int base);  // returns value of char depends on
                                         // base
long s21_strtol(char *str, char **end_ptr, int base);
long double s21_strtod(char *str, char **end_ptr);
int check_nan(char *str);
int check_inf(char *str);

long s21_strtol(char *str, char **end_ptr, int base) {
  long result = 0;
  char *ptr = skip_spaces(str);
  int sign = 1;

  if (*ptr == '-') {
    sign = -1;
    ptr++;
  }

  if (base == 16) {
    ptr += 2;
  }

  if (base == 0) {
    if (*ptr == '0') {
      ptr++;
      if ((*ptr == 'x') || (*ptr == 'X')) {
        ptr++;
        base = 16;
      } else {
        base = 8;
      }
    } else {
      base = 10;
    }
  }

  int tmp = char_value(ptr, base);
  while (tmp != -1) {
    result = result * base + tmp;
    ptr++;
    tmp = char_value(ptr, base);
  }

  if (end_ptr != s21_NULL) {
    *end_ptr = ptr;
  }

  return result * sign;
}
long double s21_strtod(char *str, char **end_ptr) {
  long double result = 0;
  char *ptr = skip_spaces(str);
  int sign = 1;

  if (*ptr == '-') {
    sign = -1;
    ptr++;
  }
  if (check_nan(ptr) == 1) {
    result = +0.0 / +0.0;
    ptr += 3;
  } else if (check_inf(ptr) == 1) {
    result = 1.0 / 0.0;
    ptr += 3;
  } else {
    int tmp = char_value(ptr, 10);
    while (tmp != -1) {
      result = result * 10 + tmp;
      ptr++;
      tmp = char_value(ptr, 10);
    }
    if (*ptr == '.') {
      double base = 0.1;
      ptr++;
      tmp = char_value(ptr, 10);
      while (tmp != -1) {
        result += base * tmp;
        base /= 10;
        ptr++;
        tmp = char_value(ptr, 10);
      }
    }
    if ((*ptr == 'E') || (*ptr == 'e')) {
      ptr++;
      int exp = s21_strtol(ptr, &ptr, 10);
      if (exp < 0) {
        for (long int i = -1; i >= exp; i--) {
          result /= 10.;
        }
      } else if (exp > 0) {
        for (long int i = 1; i <= exp; i++) {
          result *= 10.;
        }
      }
    }
  }
  if (end_ptr != s21_NULL) {
    *end_ptr = ptr;
  }
  return result * sign;
}

int char_value(char *symbol, int base) {
  int value = -1;
  if ((*symbol >= '0') && (*symbol <= '9')) {
    value = *symbol - '0';
  } else if ((*symbol >= 'a') && (*symbol <= 'z')) {
    value = *symbol - 'a' + 10;
  } else if ((*symbol >= 'A') && (*symbol <= 'Z')) {
    value = *symbol - 'A' + 10;
  }
  if (value != -1) {
    if (value / base > 0) {
      value = -1;
    }
  }
  return value;
}

char *skip_spaces(char *str) {
  char *ptr = str;
  while ((*ptr == ' ') || (*ptr == '\n')) {
    ptr++;
  }
  return ptr;
}

int check_nan(char *str) {
  int result = 1;
  char tmp[4] = "";
  char *nan = "nan";
  s21_strncpy(tmp, str, 3);
  tmp[3] = '\0';
  char *tmp_lower = s21_to_lower(tmp);
  for (int i = 0; i < 3; i++) {
    if (tmp_lower[i] != nan[i]) {
      result = 0;
    }
  }
  free(tmp_lower);
  tmp_lower = s21_NULL;
  return result;
}

int check_inf(char *str) {
  int result = 1;
  char tmp[4] = "";
  char *inf = "inf";
  s21_strncpy(tmp, str, 3);
  tmp[3] = '\0';
  char *tmp_lower = s21_to_lower(tmp);
  for (int i = 0; i < 3; i++) {
    if (tmp_lower[i] != inf[i]) {
      result = 0;
    }
  }
  free(tmp_lower);
  tmp_lower = s21_NULL;
  return result;
}