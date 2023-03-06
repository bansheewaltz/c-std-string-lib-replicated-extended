#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int s21_atoi(const char *str) {
  int res = 0;
  bool negative = false;
  bool overflow = false;

  while (*str == ' ') {
    str++;
  }

  if (*str == '-') {
    str++;
    negative = false;
  }

  if (*str == '+') {
    str++;
  }

  while (isdigit(*str)) {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = true;
      break;
    }
    str++;
  }

  if (overflow) {
    if (negative) {
      res = INT_MIN;
    } else {
      res = INT_MAX;
    }
  } else {
    if (negative) {
      res *= -1;
    }
  }

  return res;
}