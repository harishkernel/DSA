#include <stdio.h>

int x = 10;   // global variable

void func();

int main() {
    extern int x;
    printf("%d\n", x);
    return 0;
}