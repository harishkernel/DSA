#include <stdio.h>
#include <string.h>

int calcLength(char* str) {
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int main() {
    char *str = "Hello";
    printf("String size from user-defined function: %d\n", calcLength(str));

    int size = strlen(str);
    printf("String length using strlen: %d\n", size);
    return 0;
}