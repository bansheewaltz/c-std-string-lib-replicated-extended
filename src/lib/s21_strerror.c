#include <errno.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *stringErr = (char *)malloc(200 * sizeof(char));
  char *arrErre[200] = arrErr;

  if (errnum < ERROUTSIZE && errnum >= 0) {
    stringErr = arrErre[errnum];
  } else {
    s21_sprintf(stringErr, "%s%d", ERROUT, errnum);  // ЗАМЕНИТЬ НА СВОЮ
  }
  return stringErr;
}

/*Тесты:
s21_strerror(1);
s21_strerror(134);
*/