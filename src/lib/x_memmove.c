#include "x_string.h"
#include "stdlib.h"

void *x_memmove(void *dest, const void *src, x_size_t n) {
  if (n != 0) {
    char *dest0 = (char *)dest;
    char *src0 = (char *)src;

    char *tmp = (char *)malloc(sizeof(char) * n);
#ifdef MALLOC_FAIL_VALUE
    if (n == MALLOC_FAIL_VALUE) {
      free(tmp);
      tmp = x_NULL;
    }
#endif

    if (tmp != x_NULL) {
      x_memcpy(tmp, src0, n);
      x_memcpy(dest0, tmp, n);
      free(tmp);
    }
  }

  return dest;
}
