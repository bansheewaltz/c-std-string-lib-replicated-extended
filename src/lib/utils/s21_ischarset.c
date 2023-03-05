#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

bool s21_ischarset(char c, int n, ...) {
  bool result = false;

  va_list args;
  va_start(args, n);
  for (int i = 0; i < n; ++i) {
    if (c == va_arg(args, int)) {
      result = true;
      break;
    }
  }
  va_end(args);

  return result;
}