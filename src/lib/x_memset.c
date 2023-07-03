#include "x_string.h"

void *x_memset(void *str, int c, x_size_t n) {
  char *str0 = (char *)str;

  while (n--) {
    *str0++ = c;
  }

  return str;
}
