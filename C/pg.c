#include<stdio.h>

int main() {
    int v[106];
    int n=0,i;
    char c;
    while(scanf("%d", &v[n])==1) {
       n++;
    }
    for(i=0;i<n;i++) {
        printf("%d ", v[i]);
    }
        //printf("%d", n);
}
