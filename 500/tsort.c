#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 10
#define BUFSIZE (8 + 1)

int compare(char *s1, char *s2) {
    /*
     * FIXME: Not considering zero left digits
     */

    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int i;

    if (length1 > length2) {
        return -1;
    } else if (length1 < length2) {
        return 1;
    }

    for (i = 0; i < length1 && s1[i] != '\n' && s2[i] != '\n'; i++) {
        if(s1[i] < s2[i]) {
            return 1;
        }
        if (s1[i] > s2[i]) {
            return -1;
        }
    }

    return 0;
}

void heapsort(char **elements, int size) {
    int i = size / 2;
    int parent, leaf;
    char *valor = (char *) malloc( BUFSIZE * sizeof(char));

    for (;;) {
        if (i > 0) {
            i--;
            strcpy(valor, elements[i]);
        } else {
            size--;
            if (size == 0) {
                return;
            }
            strcpy(valor, elements[size]);
            strcpy(elements[size], elements[0]);
        }

        parent = i;
        leaf = 2*i + 1;
        while (leaf < size) {
            if ((leaf + 1 < size) && (compare(elements[leaf], elements[leaf + 1]) > 0)) {
                leaf++;
            }
            if (compare(elements[leaf], valor) < 0) {
                strcpy(elements[parent], elements[leaf]);
                parent = leaf;
                leaf = parent * 2 + 1;
            } else {
                break;
            }
        }
        strcpy(elements[parent], valor);
    }

}



void radixsort(char **v, int size) {

}

void fgetsFromStdin(char *str) {
    fgets(str, BUFSIZE, stdin);
    str[strlen(str) - 1] = '\0';
}

int main(int argc, char *argv) {
  int n, i = 0;
  char **buf;

  scanf("%d\n", &n);
  buf = (char **) malloc(n * sizeof(char *));

  for (i = 0; i < n; i++) {
    buf[i] = (char *) malloc(BUFSIZE * sizeof(char));
    fgetsFromStdin(buf[i]);
  }

  //heapsort(buf, n);

  for (i = 0; i < n; i++) {
    printf("%s\n", buf[i]);
  }

  return 0;
}
