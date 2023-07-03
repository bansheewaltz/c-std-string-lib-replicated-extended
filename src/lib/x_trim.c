#include <stdlib.h>

#include "x_string.h"
#include "x_utils.h"

void *x_trim(const char *src, const char *trim_chars) {
  char *result = x_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      x_size_t len_src = x_strlen(src);
      x_size_t len_chars = x_strlen(trim_chars);

      x_trim_l(&src, trim_chars, &len_src, len_chars);
      if (len_src) x_trim_r(&src, trim_chars, &len_src, len_chars);

      result = (char *)malloc(sizeof(char) * (len_src + 1));

      if (result) {
        for (x_size_t i = 0; i < len_src + 1; i++) {
          if (i < len_src) {
            result[i] = src[i];
          } else {
            result[i] = '\0';
          }
        }
      }
    } else {
      result = x_trim(src, " \t\n");
    }
  }

  return result;
}

void x_trim_l(const char **src, const char *trim_chars, x_size_t *src_len,
                const x_size_t trim_chars_len) {
  x_size_t m = 0;

  while (src && m != trim_chars_len) {
    if ((**src) == trim_chars[m]) {
      (*src)++;
      (*src_len) -= 1;
      m = 0;
      continue;
    }
    m++;
  }
}

void x_trim_r(const char **src, const char *trim_chars, x_size_t *src_len,
                const x_size_t trim_chars_len) {
  x_size_t m = 0;
  x_size_t i = (*src_len) - 1;

  while (src && m != trim_chars_len) {
    if ((*src)[i] == trim_chars[m]) {
      i--;
      (*src_len)--;
      m = 0;
      continue;
    }

    m++;
  }
}
