#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k, t = 0;
  char digit;
  int sum = 0;

  /*
   * 1. set the buffer mode
   */
  setvbuf(stdin, (char *) NULL, _IOFBF, sizeof(char));

  scanf("%d %d\n", &n, &k);

  /*
   * 2. read raw input character, one by one, for each line
   */
  while (n > 0) {
    digit = getchar_unlocked();
    /*
     * 3. make the character conversion
     */
    if (digit == '\n') {
      if (t % k == 0) {
	sum += 1;
      }
      --n;
      t = 0;
    } else {
      t = digit - '0' + 10 * t;
    }
  }
  
  printf("%d\n", sum);

  return 0;
}
