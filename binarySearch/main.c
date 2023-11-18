#include "stdio.h"

struct Result {
    int iterations;
    int index;
};

struct Result binarySearch (int tgt, int arr[], int size) {
    struct Result result;
    result.iterations = 0;
    result.index = -1;

    int low  = 0;
    int high = size;
    int mid;

    while (low < high) {
        result.iterations++;
        mid = (high + low) / 2;

        if (arr[mid] > tgt) {
            high = mid - 1;
        } else if (arr[mid] < tgt) {
            low = mid + 1;
        } else {
            result.index= mid;
            return result;
        }
    }

    return result;
}

int main () {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 6;
    struct Result result = binarySearch(target, array, size);
    printf("%d was found at index %d and took %d iterations", target, result.index, result.iterations);

    return 0;
};
