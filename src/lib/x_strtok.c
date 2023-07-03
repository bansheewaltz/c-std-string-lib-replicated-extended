#include "x_string.h"

char* x_strtok(char* str, const char* delim) {
  static char* buffer = x_NULL;
  char* result = x_NULL;

  if (str != x_NULL) {
    buffer = str;
  }

  if (buffer != x_NULL) {
    buffer += x_strspn(buffer, delim);

    if (*buffer != '\0') {
      char* const tokenBegin = buffer;
      buffer += x_strcspn(buffer, delim);

      if (*buffer != '\0') {
        *buffer++ = '\0';
      }
      result = tokenBegin;
    }
  }
  return result;
}
