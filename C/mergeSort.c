#include <stdio.h>

void merge(int* arr, int low, int mid, int high) {
    int temp[high - low + 1];
    int i = low, j = mid+1, k = 0;

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];

    for(int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSort(int* arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {4, 3, 5, 1, 2};
    int n = 5;

    printf("Before merge sort: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    mergeSort(arr, 0, n-1);

    printf("\nAfter merge sort: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
}