#include <stdio.h>
#include <string.h>

int main() {
    int n = 5;
    char arr[n][100];
    char temp[100];

    printf("Reading arr elements\n");

    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                // first string is greater than 2nd string
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    printf("After sorting: ");
    for(int i = 0; i < 5; i++) {
        printf("%s ", arr[i]);
    }
}