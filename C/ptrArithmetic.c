#include <stdio.h>

void update(int* x) {
    int y = *x;
    y++;
    *x = y;
}

int main() {
    int x = 10;
    printf("Before updating: %d\n", x);

    update(&x);
    printf("After updating: %d\n", x);
}