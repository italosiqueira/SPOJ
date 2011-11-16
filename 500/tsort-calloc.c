#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv) {
    unsigned int *arr,i,x,no,count=0,j,max=0;

    scanf("%u",&no);
    arr = calloc(1000001,sizeof(int));
    j = no;
    while(no > 0 ) {
        scanf("%u",&x);
        arr[x]=arr[x]+1;
        if(x > max)
        max=x;
        no--;
    }
    no = j;
    for( i=0;i<=max;i++) {
        while (arr[i]) {
            printf("%u\n",i);
            arr[i]=arr[i]-1;
        }
    }

    return 0;
}
