#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* buffer = s21_NULL;
  char* result = s21_NULL;

  if (str != s21_NULL) {
    buffer = str;
  }

  if (buffer != s21_NULL) {
    buffer += s21_strspn(buffer, delim);

    if (*buffer == '\0') {
      result = s21_NULL;
    } else {
      char* const tokenBegin = buffer;
      buffer += s21_strcspn(buffer, delim);

      if (*buffer != '\0') {
        *buffer++ = '\0';
      }
      result = tokenBegin;
    }
  } else {
    result = s21_NULL;
  }
  return result;
}
