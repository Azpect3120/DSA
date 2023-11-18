#include "stdio.h"

struct Result {
    int size;
    int *array;
    int arrayAccesses;
};

int partition (struct Result *result, int low, int high) {
    int pivot = result->array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (result->array[j] <= pivot) {
            i++;
            int temp = result->array[i];
            result->array[i] = result->array[j];
            result->array[j] = temp;
            result->arrayAccesses += 3;
        }
    }

    int temp = result->array[i+1];
    result->array[i+1] = result->array[high];
    result->array[high] = temp;
    result->arrayAccesses += 3;
    
    return i+1;
}

void quickSort (struct Result *result, int low, int high) {
    if (low < high) {
        int pivot = partition(result, low, high);

        quickSort(result, low, pivot - 1);
        quickSort(result, pivot + 1, high);
    }
}


void printArray (struct Result *result) {
    for (int i = 0; i < result->size; i++) {
        printf("%d ", result->array[i]);
    }
    printf("\n");
}

int main () {
    struct Result result;
    int unsorted[100] = {84, 36, 19, 50, 72, 11, 93, 68, 7, 88, 20, 5, 45, 62, 77, 30, 53, 96, 15, 83, 41, 3, 66, 22, 74, 97, 28, 60, 9, 89, 48, 64, 14, 75, 39, 81, 26, 58, 33, 99, 17, 49, 91, 12, 69, 44, 78, 21, 55, 90, 8, 31, 63, 80, 38, 72, 2, 87, 51, 23, 98, 16, 43, 70, 29, 56, 86, 34, 59, 92, 13, 67, 25, 46, 71, 35, 82, 1, 76, 52, 95, 18, 42, 61, 79, 24, 57, 40, 85, 10, 54, 32, 94, 6, 73, 47, 37, 65, 27, 50};

    result.array = unsorted;
    result.size = sizeof(unsorted) / sizeof(unsorted[0]);

    printArray(&result);
    quickSort(&result, 0, result.size - 1);
    printArray(&result);

    printf("%d", result.arrayAccesses);

    return 0;
}
