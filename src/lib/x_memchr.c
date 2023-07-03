#include "x_string.h"

void *x_memchr(const void *str, int c, x_size_t n) {
  const unsigned char *src = (const unsigned char *)str;
  void *result = x_NULL;

  while (n-- > 0) {
    if (*src == c) {
      result = (void *)src;
      break;
    }
    src++;
  }

  return result;
}
