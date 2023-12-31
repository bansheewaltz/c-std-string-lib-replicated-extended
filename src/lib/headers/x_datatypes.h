#ifndef HEADERS_x_DATATYPES_H_
#define HEADERS_x_DATATYPES_H_

#include <stdbool.h>

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int precision;
  int is_precision_set;
  int width;
  char length;
  char specifier;
} specifications;

#endif  // HEADERS_x_DATATYPES_H_
