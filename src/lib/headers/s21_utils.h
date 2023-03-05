#ifndef HEADERS_S21_UTILS_H_
#define HEADERS_S21_UTILS_H_

#include <stdbool.h>
#include <stdint.h>

#include "s21_string.h"
#define BUFF_SIZE 512

// helper functions
bool s21_ischarset(char c, int n, ...);
// string functions that don't belong to public header of the library
int s21_atoi(const char *str);
char *s21_itoa(int64_t n, char *buffer, int radix);
char *s21_uitoa(uint64_t n, char *buffer, int radix);
void s21_trim_r(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len);
void s21_trim_l(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len);

#endif  //  HEADERS_S21_UTILS_H_