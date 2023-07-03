#include <errno.h>
#include <stdlib.h>

#include "x_string.h"

char *x_strerror(int errnum) {
  static char stringErr[200] = "";
  char *arrErre[200] = arrErr;

  if (errnum < ERROUTSIZE && errnum >= 0) {
    x_strcpy(stringErr, arrErre[errnum]);
  } else {
    x_sprintf(stringErr, "%s%d", ERROUT, errnum);
  }
  return stringErr;
}
