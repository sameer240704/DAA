#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* p1, int* p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int limit = partition(array, low, high);
        quick_sort(array, low, limit - 1);
        quick_sort(array, limit + 1, high);
    }
}

int main() {
    int length;
    bool flag = false, checked = false;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int *array = (int*) malloc (length * sizeof(int));

    printf("\nEnter the array: ");
    for(int i = 0 ; i < length ; i++) {
        scanf("%d", &array[i]);
        if(checked == false && i > 0 && array[i-1] > array[i]) {
            flag = true;
            checked = true;
        }
    }

    if(flag == true)
        quick_sort(array, 0, length - 1);
  
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) 
        printf("%d ", array[i]);

    free(array);

    return 0;
}