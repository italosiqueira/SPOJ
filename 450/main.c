#include <stdio.h>

int main() {
  int n, k, t, i;
  int count = 0;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    count += !(t % k);
  }

  printf("%d\n",count);

  return 0;
}
