#include <stdio.h>

int linearSearch(int* arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int n, int key) {
    int low = 0, high = n-1;
    while(low < high) {
        int mid = (low+high>>1);
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    printf("linearSearch(%d): %d\n", key, linearSearch(arr, n, key));
    printf("binarySearch(%d): %d\n", key, binarySearch(arr, n, key));
}