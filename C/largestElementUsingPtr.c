#include <stdio.h>

int main() {
    int arr[] = {5, 4, 19, 3, 2, 12, 919, 190, 1e9+7};
    int n = sizeof(arr) / sizeof(int);
    int *p = arr;   // p --> holds the base-address of arr[0]
    int maxi = *p;  // maxi assumes max-val is *p (i.e., *p = arr[0])
    
    for(int i = 0; i < n; i++) {
        if(*(p + i) > maxi) {
            maxi = *(p + i);
        }
    }
    printf("Maximum element in arr: %d\n", maxi);
    return 0;
}