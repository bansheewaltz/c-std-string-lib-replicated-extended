#include <stdlib.h>

#include "x_string.h"

void *x_insert(const char *src, const char *str, x_size_t start_index) {
  char *res = x_NULL;
  if (src && str == x_NULL) {
    res = calloc(x_strlen(src) + 1, 1);
    x_strcat(res, src);
  } else if (src && str && x_strlen(src) >= start_index) {
    res = malloc((x_strlen(src) + x_strlen(str) + 1) * sizeof(char));
    if (res) {
      x_strncpy(res, src, start_index);
      *(res + start_index) = '\0';
      x_strcat(res, str);
      x_strcat(res, src + start_index);
    }
  }
  return res;
}
