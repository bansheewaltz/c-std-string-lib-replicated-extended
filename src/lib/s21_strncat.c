#include "s21_string.h"

/*char *strncat(char *dest, const char *src, size_t n)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает
dest, длиной до n символов.*/

/*char str1[15] = "This is ", str2[] = "win";
 printf("%s", s21_strncat(str1, str2, 2)); == This is wi
*/

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }

  s21_size_t i = 0;
  while (*src != '\0' && i < n) {
    *ptr++ = *src++;
    i++;
  }
  *ptr = '\0';
  return dest;
}
