#include <stdio.h>

union Data {
    int i;
    float f;
};

int main() {
    union Data d;
    d.i = 10;
    printf("%d\n", d.i);
    d.f = 2.5;
    printf("%.2f", d.f);
    return 0;
}