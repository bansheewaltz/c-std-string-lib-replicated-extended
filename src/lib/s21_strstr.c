#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  while (*haystack != '\0') {
    if ((*haystack == *needle) && comp(haystack, needle))
      return (char *)haystack;
    haystack++;
  }
  return NULL;
}

int comp(const char *haystack, const char *needle) {
  while (*haystack && *needle) {
    if (*haystack != *needle) return 0;
    haystack++;
    needle++;
  }
  return (*needle == '\0');
}