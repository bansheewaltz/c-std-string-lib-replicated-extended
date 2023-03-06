#ifndef HEADERS_S21_SPRINTF_H_
#define HEADERS_S21_SPRINTF_H_

#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

#include "s21_datatypes.h"
int s21_sprintf(char *str, const char *format, ...);

// helper functions
void s21_dtostr(long double val, char *ret, specifications *);
bool specifier_is_correct(int symbol);
bool check_integer_specifier(char c);
bool is_integer_specifier(char c);
bool is_all_zeroes(char *buff);
void whole_num_to_string(int64_t val, char *ret, int base);
void unsigned_num_to_string(uint64_t val, char *ret, int base);
void to_upper(char *str);
void prepend_ox(char *buff, specifications *);
void prepend_mantissa(char *str, int pow, char sign);
void remove_trailing_zeroes(char *buff);

// scan format
const char *scan_flags(const char *format, specifications *);
const char *scan_width(const char *format, specifications *, va_list *va);
const char *scan_precision(const char *format, specifications *, va_list *va);
const char *scan_length(const char *format, specifications *);

// parse values
void parse_value(specifications *, char *buff, va_list *va);
void parse_int(specifications *, char *buff, va_list *va);
void parse_uint(specifications *, char *buff, va_list *va);
void parse_octal(specifications *, char *buff, va_list *va);
void parse_hex(specifications *, char *buff, va_list *va);
void parse_char(specifications *, char *buff, va_list *va);
void parse_string(specifications *, char *buff, va_list *va);
void parse_float(specifications *, char *buff, va_list *va);
void parse_mantissa(specifications *, char *buff, va_list *va);
void parse_float_g_G(specifications *, char *buff, va_list *va);
void parse_pointer(specifications *, char *buff, va_list *va);

// format values
void format_precision(char *buff, specifications *);
void format_flags(char *buff, specifications *);
void format_gG_precision(char *buff, int precision);
void format_char(specifications *, char *buff, char c);
void format_string(specifications *, char *buff, char *str);

#endif  //  HEADERS_S21_SPRINTF_H_