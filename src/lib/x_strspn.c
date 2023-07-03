#include "x_string.h"

x_size_t x_strspn(const char *str1, const char *str2) {
  int result = 0;
  int flag = 0;
  for (x_size_t i = 0; i < x_strlen(str1); i++) {
    for (x_size_t j = 0; j < x_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag++;
        break;
      }
    }
    if (flag == 0) {
      break;
    } else {
      result++;
      flag = 0;
    }
  }
  return result;
}
