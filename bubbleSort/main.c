#include "stdio.h"

struct Result {
    int size;
    int *array;
    int arrayAccesses;
};


void bubbleSort (struct Result *result) {
    for (int i = 0; i < result->size; i++) {
        for (int j = i; j < result->size; j++) {
            if (result->array[i] > result->array[j]) {
                int temp = result->array[i];
                result->array[i] = result->array[j];
                result->array[j] = temp;
                result->arrayAccesses += 3;
            }
        }
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
    bubbleSort(&result);
    printArray(&result);

    printf("%d", result.arrayAccesses);

    return 0;
}
