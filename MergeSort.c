#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a > b ? b : a;
}

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int *array = (int*) malloc (length * sizeof(int));

    printf("\nEnter the array:\n");
    for(int i = 0 ; i < length ; i++) 
        scanf("%d", &array[i]);

    merge_sort(array, length);

    printf("\nSorted Array: ");
    for(int i = 0 ; i < length ; i++) 
        printf("%d ", array[i]);

    free(array);
    return 0;
}