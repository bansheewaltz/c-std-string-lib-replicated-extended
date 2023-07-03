#include "x_string.h"

char *x_strncpy(char *dest, const char *src, x_size_t n) {
  if (n > 0) {
    x_memset(dest, '\0', n);

    for (x_size_t i = 0; i < n && src[i]; i++) {
      dest[i] = src[i];
    }
  }

  return dest;
}
