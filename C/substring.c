#include <stdio.h>
#include <string.h>

int find(char* str, char* key) {
    int n = strlen(str);

    for(int i = 0; i < n; i++) {
        if(key[i] == str[i]) {
            return -1;
        }
    }
}

int main() {
    char* str = "hello world";
    // to find starting pos of "he"

    char* key = "he";

    int ans = find(str, key);

    printf((ans == -1) ? "%s\n" : "%s\n", "Not found", "Found at idx %d", ans);
    
}