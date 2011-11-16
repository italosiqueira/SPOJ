#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 32 * 1024

int main() {
  int n, k, t = 0, i = 0, readed = 0;
  char buf[BUFSIZE + 1] = {'0'};
  int sum = 0;

  scanf("%d %d\n", &n, &k);

  while ((readed = fread(buf, sizeof(char), BUFSIZE, stdin)) > 0) {
    
    for (i = 0; i < readed; i++) {
      if (buf[i] == '\n') {
	if (t % k == 0) {
	  sum += 1;
	}
	--n;
	printf("Faltam %d números...\n", n);
	t = 0;
      } else {
	t = buf[i] - '0' + 10 * t;
      }
    }
    if (n == 0) {
      break;
    }
  }
  
  printf("%d\n", sum);

  return 0;
}
