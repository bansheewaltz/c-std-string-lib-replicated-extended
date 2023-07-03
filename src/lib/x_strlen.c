#include "x_string.h"

x_size_t x_strlen(const char *s) {
  x_size_t result = 0;
  while ((s[result]) != '\0') {
    result++;
  }
  return result;
}
