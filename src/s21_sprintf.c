#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_string.h"
#include "utils/s21_utils.h"
#define INT_BUFFER (10 + 1 + 1)  // +1 for sign +1 for null-terminator
#define BUFFER 512

bool specifier_is_correct(int symbol) {
  return s21_strchr("cdeEfgiGnopsuxX", symbol) != s21_NULL;
}

void print_int(char **str, va_list args, int base) {
  int value = va_arg(args, int);
  char ascii_str[INT_BUFFER] = "";

  s21_itoa(value, ascii_str, base);
  s21_strcat(*str, ascii_str);
  *str += s21_strlen(ascii_str);
}

void prepend_ox(char **str) {
  s21_memmove(*str + 2, *str, s21_strlen(*str));
  (*str)[0] = '0';
  (*str)[1] = 'x';
  *str += 2;
}

void print_uint(char **str, va_list args, int base) {
  s21_size_t value = va_arg(args, s21_size_t);
  char ascii_str[INT_BUFFER] = "";

  s21_size_t i = 0;
  for (; value != 0; value /= base, ++i) {
    ascii_str[i] = "0123456789abcdef"[value % base];
  }

  s21_size_t len = i;
  unsigned char tmp;
  for (s21_size_t j = i - 1, i = 0; i < j; ++i, --j) {
    tmp = ascii_str[i];
    ascii_str[i] = ascii_str[j];
    ascii_str[j] = tmp;
  }

  s21_strcat(*str, ascii_str);
  if (base == 16) {
    prepend_ox(str);
  }
  *str += len;
}

void print_str(char **str, va_list args) {
  char *src = va_arg(args, char *);
  s21_strcat(*str, src);
  *str += s21_strlen(src);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  str[0] = '\0';
  char *str_beginning = str;

  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
    }
    if (specifier_is_correct(*format)) {
      if (*format == 'c') {
        char c = va_arg(args, int);
        *str++ = c;
      }
      if (*format == 'd' || *format == 'i') {
        print_int(&str, args, 10);
      }
      if (*format == 'o') {
        print_int(&str, args, 8);
      }
      if (*format == 'x' || *format == 'X' || *format == 'p') {
        print_uint(&str, args, 16);
      }
      if (*format == 's') {
        print_str(&str, args);
      }
      format++;
    } else {
      puts("unknown conversion type character in format");
      break;
    }
  }

  *str = '\0';
  va_end(args);
  return str - str_beginning;
}

int main() {
  char string[100] = "1234";
  // char ch = 'a'`;
  int i = 29;
  int *p = &i;

  s21_sprintf(string, "%x", i);
  puts(string);
  s21_sprintf(string, "%p", p);
  puts(string);

  sprintf(string, "%x", i);
  puts(string);
  sprintf(string, "%p", p);
  puts(string);
}
