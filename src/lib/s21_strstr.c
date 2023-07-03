#include <stdbool.h>

#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      bool found = true;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = false;
          break;
        }
      }
      if (found) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}
