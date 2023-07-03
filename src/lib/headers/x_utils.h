#ifndef HEADERS_x_UTILS_H_
#define HEADERS_x_UTILS_H_

#include <stdbool.h>
#include <stdint.h>

#include "x_string.h"
#define BUFF_SIZE 512

// helper functions
bool x_ischarset(char c, int n, ...);
// string functions that don't belong to public header of the library
int x_atoi(const char *str);
char *x_itoa(int64_t n, char *buffer, int radix);
char *x_uitoa(uint64_t n, char *buffer, int radix);
void x_trim_r(const char **src, const char *trim_chars, x_size_t *src_len,
                const x_size_t trim_chars_len);
void x_trim_l(const char **src, const char *trim_chars, x_size_t *src_len,
                const x_size_t trim_chars_len);

char *skip_spaces(char *str);
int char_value(char *symbol, int base);
long x_strtol(char *str, char **end_ptr, int base);
long double x_strtod(char *str, char **end_ptr);

#endif  //  HEADERS_x_UTILS_H_
