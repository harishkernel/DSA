#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = 0, b = 1;
    int c = a+b;
    while(c < n) {
        printf("%d ",c);
        c = a+b;
        a = b;
        b = c;
    }
    return 0;
}