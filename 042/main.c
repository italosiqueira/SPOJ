#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 9

static char digits[] = "0123456789";

char digitToChar10(int value) {
  return digits[value % 10];
}

int charToDigit10(char c) {
  return c - '0';
}

char *addReversedValues(char *value1, char *value2) {
  char *r, *s1, *s2;
  int mod = 0, i, r_pos = 0, len = 0, d;

  if (strlen(value2) > strlen(value1)) {
    len = strlen(value2);
    s1 = value2;
    s2 = value1;
  } else {
    len = strlen(value1);
    s1 = value1;
    s2 = value2;
  }

  r = (char *) malloc(len * sizeof(char) + 2); // for the '\0' and final mod
  for (i = 0; i < len; i++) {
    if (i < strlen(s2)) {
      d = charToDigit10(s1[i]) + charToDigit10(s2[i]);
    } else {
      d = charToDigit10(s1[i]);
    }
    if (mod > 0) {
      ++d;
      mod = 0;
    }
    if (d >= 10) {
      d = d % 10;
      mod = 1;
    }
    r[r_pos] = digitToChar10(d);
    if (r[r_pos] != '0' || r_pos != 0) {
      ++r_pos;
    }
  }
  if (mod > 0) {
    r[r_pos++] = '1';
  }
  r[r_pos] = '\0';

  return r;
}

int main() {
  int n, i;
  char number1[LENGTH];
  char number2[LENGTH];
  char **answer;
  scanf("%d", &n);
  if (n > 0) {
    answer = (char **) malloc(n * sizeof(char *));
  }
  for (i = 0; i < n; i++) {
    scanf("%s %s", number1, number2);
    answer[i] = addReversedValues(number1, number2);
  }
  for (i = 0; i < n; i++) {
    printf("%s\n", answer[i]);
  }

  return 0;
}
