#include <stdio.h>
#define eps 1e-1

int main() {
    int a, n, seq;
    printf("Enter a number: ");
    scanf("%d", &a);
    n = a;
    do {
        seq = (n + a / n) / 2;
        n=seq;
    } while (seq*seq-a>eps || seq*seq-a<-eps);

    printf("approximately the root of your number is %d\n",seq);
}