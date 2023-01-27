#include "s21_string.h"

#include <stdio.h>
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

void *s21_memchr(const void *str, int c, s21_size_t n) {
  size_t i;
  for(i = 0; i < n; ++i){
    if(*((char*)str+i) == c) {
      return (char*)str+i;
    }
  }
  return NULL;
}

char *s21_strchr(const char *str, int c) {
  int i;
  while ((str[i] != '\0') && (str[i] != c)) i++;
  return c == str[i] ? (char*)str + i : NULL;
}

char *s21_strrchr(const char *str, int c) {
  char* save_c;
  char ch;

  for (save_c = (char*) 0; (ch = *str); str++ ) {
    if(ch == c) 
      save_c = (char*) str;
  }
  return save_c;
}

char *s21_strstr(const char *haystack, const char *needle) {
  while( *haystack != '\0') {
    if((*haystack == *needle) && comp(haystack, needle)) 
      return (char*)haystack;
    haystack++;
  }  
  return NULL;
}

int comp(const char *haystack, const char *needle) {
  while ( *haystack && *needle)
  {
    if (*haystack != *needle)
      return 0;
    haystack++;
    needle++;
  }
  return (*needle == '\0');
}

char *s21_strerror(int errnum) {
  switch (errnum)
  {
  case 0: return "Success";
    break;
  case 1: return "Operation not permitted";
    break;
  case 2: return "No such file or directory";
    break;
  case 3: return "No such process";
    break;
  case 4: return "Interrupted system call";
    break;
  case 5: return "Input/output error";
    break;
  case 6: return "No such device or address";
    break;
  case 7: return "Argument list too long";
    break;
  case 8: return "Exec format error";
    break;
  case 9: return "Bad file descriptor";
    break;
  case 10: return "No child processes";
    break;
  case 11: return "Resource temporarily unavailable";
    break;
  case 12: return "";
    break;
  case 13: return "";
    break;
  case 14: return "";
    break;
  case 15: return "";
    break;
  case 16: return "";
    break;
  case 17: return "";
    break;
  case 18: return "";
    break;
    case 19: return "";
    break;
    case 20: return "";
    break;
    case 21: return "";
    break;
    case 22: return "";
    break;
    case 23: return "";
    break;
    case 24: return "";
    break;
    case 25: return "";
    break;
    case 26: return "";
    break;
    case 27: return "";
    break;
    case 28: return "";
    break;
    case 29: return "";
    break;
    case 30: return "";
    break;
    case 31: return "";
    break;
    case 32: return "";
    break;
    case 33: return "";
    break;
    case 34: return "";
    break;
    case 35: return "";
    break;
    case 36: return "";
    break;
    case 37: return "";
    break;
    case 38: return "";
    break;
    case 39: return "";
    break;
    case 40: return "";
    break;
    case 41: return "";
    break;
    case 42: return "";
    break;
    case 43: return "";
    break;
    case 44: return "";
    break;
    case 45: return "";
    break;
    case 46: return "";
    break;
    case 47: return "";
    break;
    case 48: return "";
    break;
    case 49: return "";
    break;
    case 50: return "";
    break;
    case 51: return "";
    break;
    case 52: return "";
    break;
    case 53: return "";
    break;
    case 54: return "";
    break;
    case 55: return "";
    break;
    case 56: return "";
    break;
    case 57: return "";
    break;
    case 58: return "";
    break;
    case 59: return "";
    break;
    case 60: return "";
    break;
    case 61: return "";
    break;
    case 62: return "";
    break;
    case 63: return "";
    break;
    case 64: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
    case 65: return "";
    break;
  }
  return 0;
}