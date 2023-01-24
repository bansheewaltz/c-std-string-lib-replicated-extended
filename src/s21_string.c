#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag++;
        break;
      }
    }
    if (flag != 0) {
      break;
    } else {
      result++;
    }
  }
  return result;
}

s21_size_t s21_strlen(const char *s) {
  s21_size_t result = 0;
  while ((s[result]) != '\0') {
    result++;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
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

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != src && n != 0) {
    char *dest0 = (char *)dest;
    char *src0 = (char *)src;

    while (n--) {
      *dest0++ = *src0++;
    }
  }

  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest != src && n != 0) {
    char *dest0 = (char *)dest;
    char *src0 = (char *)src;

    char *tmp = (char *)malloc(sizeof(char) * n);
    if (tmp) {
      s21_memcpy(tmp, src0, n);
      s21_memcpy(dest0, tmp, n);
      free(tmp);
    }
  }

  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (n > 0) {
    char *str0 = (char *)str;

    while (n--) {
      *str0++ = c;
    }
  }

  return str;
}

char *s21_strcpy(char *dest, const char *src) {
  if (dest != src) {
    int i = 0;

    for (; src[i]; ++i) {
      dest[i] = src[i];
    }
    dest[i] = '\0';
  }

  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n > 0) {
    s21_memset(dest, '\0', n);

    for (s21_size_t i = 0; i < n && src[i]; i++) {
      dest[i] = src[i];
    }
  }

  return dest;
}
