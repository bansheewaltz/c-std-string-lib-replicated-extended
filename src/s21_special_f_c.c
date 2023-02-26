#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *buff = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t n = s21_strlen(str);
    buff = (char *)malloc(sizeof(char) * (n + 1));
    if (buff) {
      for (s21_size_t i = 0; i <= n; i++) {
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

void *s21_to_lower(const char *str) {
  char *buff = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t n = s21_strlen(str);
    buff = (char *)malloc(sizeof(char) * (n + 1));
    if (buff) {
      for (s21_size_t i = 0; i <= n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          buff[i] = (str[i] - 'A') + 'a';
        } else {
          buff[i] = str[i];
        }
      }
      buff[n] = '\0';
    }
  }
  return buff;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *buff = s21_NULL;
  if (str != s21_NULL && src != s21_NULL) {
    s21_size_t n_str = s21_strlen(str);
    s21_size_t n_src = s21_strlen(src);
    s21_size_t sum_line = n_str + n_src;
    if (n_src >= start_index) {
      buff = (char *)malloc(sizeof(char) * (sum_line + 1));
    }
    if (buff) {
      s21_size_t i = 0, j = 0, k = 0;
      while (i < sum_line) {
        if (i >= start_index && j < n_str) {
          buff[i] = str[j];
          j++;
        } else {
          buff[i] = src[k];
          k++;
        }
        i++;
      }
      buff[sum_line] = '\0';
    }
  }
  return buff;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      s21_size_t len_src = s21_strlen(src);
      s21_size_t len_chars = s21_strlen(trim_chars);

      s21_trim_l(&src, trim_chars, &len_src, len_chars);
      if (len_src) s21_trim_r(&src, trim_chars, &len_src, len_chars);

      result = (char *)malloc(sizeof(char) * (len_src + 1));

      if (result) {
        for (s21_size_t i = 0; i < len_src + 1; i++) {
          if (i < len_src) {
            result[i] = src[i];
          } else {
            result[i] = '\0';
          }
        }
      }
    } else {
      result = s21_trim(src, " \t\n");
    }
  }

  return result;
}

void s21_trim_l(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len) {
  s21_size_t m = 0;

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

void s21_trim_r(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len) {
  s21_size_t m = 0;
  s21_size_t i = (*src_len) - 1;

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