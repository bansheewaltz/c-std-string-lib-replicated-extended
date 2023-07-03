#include <stdlib.h>

#include "x_string.h"

void *x_to_upper(const char *str) {
  char *buff = x_NULL;
  if (str != x_NULL) {
    x_size_t n = x_strlen(str);

    buff = (char *)malloc(sizeof(char) * (n + 1));
#ifdef MALLOC_FAIL_VALUE
    if (n == MALLOC_FAIL_VALUE) {
      free(buff);
      buff = x_NULL;
    }
#endif

    if (buff) {
      for (x_size_t i = 0; i <= n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          buff[i] = (str[i] - 'a') + 'A';
        } else {
          buff[i] = str[i];
        }
      }
      buff[n] = '\0';
    }
  }

  return buff;
}
