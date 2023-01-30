#include <stdio.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  ;
}

int main() {
  char string[100] = "123abc";
  s21_sprintf(string, "123");
  puts(string);
}
