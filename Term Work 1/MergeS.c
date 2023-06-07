#include <stdio.h>
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
// Compare elements from both subarrays and merge them in sorted order
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
// Copy the remaining elements of the left subarray, if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
// Copy the remaining elements of the right subarray, if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;  // Base case: Array is already sorted or empty
    }
int mid = size / 2;
// Create left and right subarrays
    int left[mid];
    int right[size - mid];
// Copy elements to left and right subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    // Recursively sort the left and right subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);              // Merge the sorted subarrays
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}
