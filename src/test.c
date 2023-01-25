#include <stdio.h>
#include <string.h>
#define s21_size_t unsigned long long
void *s21_memchr(const void *str, int c, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *s);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);


int main() {
    char str[] = "12678j90";
    
    if(strchr(str, '!') != NULL ){
        printf("good\n");
        //printf("%s\n", strchr(str, '5'));

    
    }else if(s21_strchr(str, '5') != NULL)
    {
        printf("Why?\n");
        
    }else{
        printf("not good\n");
    }
}

char *s21_strchr(const char *str, int c) {
  int i;
  while (str[i] && str[i] != c) {
    printf("%c\n", str[i]);
    i++;
  }
  printf("\tstr = %d\n", str[i]);
    printf("\tc = %d\n", c);
  return c == str[i] ? (char*)str+i : NULL;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  size_t i;
  for(i = 0; i < n; ++i){
    if(*((char*)str+i) == c) {
      return (char*)str+i;
    }
  }
  return NULL;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag++;
        break;
      }
    }
    if (flag != 0) {
      break;
    } else {
      result++;
    }
  }
  return result;
}

s21_size_t s21_strlen(const char *s) {
  s21_size_t result = 0;
  while ((s[result]) != '\0') {
    result++;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag++;
        break;
      }
    }
    if (flag == 0) {
      break;
    } else {
      result++;
      flag = 0;
    }
  }
  return result;
}