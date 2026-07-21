#include <stdio.h>

struct MyStruct {
    int i;    // Takes 4 bytes
    float f;  // Takes 4 bytes
};            // Total size: ~8 bytes

union MyUnion {
    int i;    // Takes 4 bytes
    float f;  // Takes 4 bytes
};            // Total size: ~4 bytes (The largest member's size)

int main() {
    struct MyStruct s;
    union MyUnion u;

    // 1. Proving the Memory Size Difference
    printf("Size of Structure: %lu bytes\n", sizeof(s));
    printf("Size of Union: %lu bytes\n\n", sizeof(u));

    printf("--- Union Memory Test ---\n");
    
    u.i = 10; 
    printf("Assigned Integer. Value of i: %d\n", u.i);
    
    u.f = 2.5; 
    printf("Assigned Float. Value of f: %.2f\n", u.f);
    
    // Printing 'i' now will show a garbage value because 'f' overwrote its memory!
    printf("Checking Integer again: %d (Corrupted!)\n", u.i);

    return 0;
}