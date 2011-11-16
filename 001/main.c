#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int main(int argc, char *argv[])
{
  int values[BUFSIZE];
  int pos = 0;
  int i = 0;
  scanf("%d", &values[pos]);
  while (values[pos++] != 42 && pos < BUFSIZE) {
    scanf("%d", &values[pos]);
  }

  for (i = 0; i < pos - 1; i++) {
    printf("%d\n", values[i]);
  }

  return 0;
}
