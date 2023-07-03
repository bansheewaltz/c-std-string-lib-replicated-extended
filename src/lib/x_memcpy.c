#include "x_string.h"

void *x_memcpy(void *dest, const void *src, x_size_t n) {
  if (n != 0) {
    char *dest0 = (char *)dest;
    char *src0 = (char *)src;

    while (n--) {
      *dest0++ = *src0++;
    }
  }

  return dest;
}
