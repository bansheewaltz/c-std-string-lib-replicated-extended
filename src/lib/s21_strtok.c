#include "s21_string.h"

/*char *strtok(char *str, const char *delim)
Разбивает строку str на ряд токенов, разделенных delim.*/

char *s21_strtok(char *str, const char *delim) {
  static char *p = 0;
  if (str)
    p = str;
  else if (!p)
    return 0;
  str = p + s21_strspn(p, delim);    // ЗАМЕНИТЬ НА СВОЮ
  p = str + s21_strcspn(str, delim); // ЗАМЕНИТЬ НА СВОЮ
  if (p == str)
    return p = 0;
  p = *p ? *p = 0, p + 1 : 0;
  return str;
}
/*Тест:
char str[80] = "This is - www.com - website";
const char s[2] = "-";
char *token;
token = s21_strtok(str, s); == This is
*/