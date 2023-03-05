#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }

  while (*src != '\0') {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}
/*Тесты:
strcat(NULL, NULL); == segmentation fault
char str1[100] = "This is ", str2[] = "win";
printf("%s", s21_strcat(str1, str2)); == This is win
*/
