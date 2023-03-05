#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#include "s21_datatypes.h"
#include "s21_sprintf.h"
#include "s21_utils.h"

void s21_dtostr(long double val, char *ret, specifications *specs) {
  char buff[BUFF_SIZE] = "";
  int idx = BUFF_SIZE - 2;
  bool neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (specs->precision == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFF_SIZE] = "";
  for (int i = 0; i < specs->precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < specs->precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((specs->is_precision_set && specs->precision != 0) || (int)r ||
      (!specs->is_precision_set && val == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (neg && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[idx + 1];
  }
}

void parse_mantissa(specifications *specs, char *buff, va_list *va) {
  long double val = 0;
  if (specs->length == 'L') {
    val = va_arg(*va, long double);
  } else {
    val = va_arg(*va, double);
  }
  int pow = 0;
  char sign = (int)val == 0 ? '-' : '+';

  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }

  if (!specs->is_precision_set) specs->precision = 6;
  s21_dtostr(val, buff, specs);
  prepend_mantissa(buff, pow, sign);
  format_flags(buff, specs);
}

void prepend_mantissa(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = pow % 10 + '0';
  pow /= 10;
  str[len + 2] = pow % 10 + '0';
  str[len + 4] = '\0';
}
