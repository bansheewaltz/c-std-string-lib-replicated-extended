#include "x_string.h"

char *x_strncat(char *dest, const char *src, x_size_t n) {
  char *ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }

  x_size_t i = 0;
  while (*src != '\0' && i < n) {
    *ptr++ = *src++;
    i++;
  }
  *ptr = '\0';
  return dest;
}
