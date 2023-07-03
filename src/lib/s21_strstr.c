#include "s21_string.h"
int comp(const char *haystack, const char *needle);

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  while (*haystack != '\0' && result == s21_NULL) {
    if ((*haystack == *needle) && comp(haystack, needle))
      result = (char *)haystack;
    haystack++;
  }
  return result;
}

int comp(const char *haystack, const char *needle) {
  int result = 1;
  while (*haystack && *needle && result != 0) {
    if (*haystack != *needle) result = 0;
    haystack++;
    needle++;
  }
  return result == 1 ? (*needle == '\0') : 0;
}
