#include "x_string.h"

char *x_strcpy(char *dest, const char *src) {
  int i = 0;

  for (; src[i]; ++i) {
    dest[i] = src[i];
  }
  dest[i] = '\0';

  return dest;
}
