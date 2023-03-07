#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *src = (const unsigned char *)str;
  void *result = s21_NULL;

  while (n-- > 0) {
    if (*src == c) {
      result = (void *)src;
      break;
    }
    src++;
  }

  return result;
}