#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#include "s21_string.h"

char* s21_itoa(int64_t n, char* buffer, int radix) {
  if (radix < 2 || radix > 32) {
    return buffer;
  }

  char* buff0 = buffer;
  char tmp[sizeof n * CHAR_BIT + 1];

  bool neg = (radix == 10 && n < 0);
  n = neg ? -n : n;

  int i = 0;
  if (n == 0) {
    tmp[i++] = '0';
  }
  while (n > 0) {
    tmp[i++] = "0123456789abcdef"[n % radix];
    n /= radix;
  }

  if (neg) {
    *buffer++ = '-';
  }
  while (i) {
    *buffer++ = tmp[--i];
  }
  *buffer = '\0';

  return buff0;
}