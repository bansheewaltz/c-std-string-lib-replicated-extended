char *s21_itoa(int value, char *result, int base);
void s21_trim_r(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len);
void s21_trim_l(const char **src, const char *trim_chars, s21_size_t *src_len,
                const s21_size_t trim_chars_len);