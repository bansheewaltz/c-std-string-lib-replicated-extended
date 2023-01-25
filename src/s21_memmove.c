#include "s21_string.h"
#include "stdlib.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest != src && n != 0) {
    char *dest0 = (char *)dest;
    char *src0 = (char *)src;

    char *tmp = (char *)malloc(sizeof(char) * n);
    if (tmp) {
      s21_memcpy(tmp, src0, n);
      s21_memcpy(dest0, tmp, n);
      free(tmp);
    }
  }

  return dest;
}
