#include "x_string.h"

char *x_strchr(const char *str, int c) {
  char *result = x_NULL;
  const char *tmp_ptr = str;
  while (*tmp_ptr != '\0') {
    if (*tmp_ptr == c) {
      result = (char *)tmp_ptr;
      break;
    }
    tmp_ptr += 1;
  }
  if (*tmp_ptr == c) {
    result = (char *)tmp_ptr;
  }
  return result;
}
