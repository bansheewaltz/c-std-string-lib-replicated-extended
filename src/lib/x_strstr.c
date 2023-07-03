#include <stdbool.h>

#include "x_string.h"

char *x_strstr(const char *haystack, const char *needle) {
  char *res = x_NULL;
  if (x_strlen(haystack) >= x_strlen(needle)) {
    for (x_size_t i = 0; i <= x_strlen(haystack) - x_strlen(needle);
         i++) {
      bool found = true;
      for (x_size_t j = i, k = 0; needle[k]; k++, j++) {
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
