#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int binarySearch(int tgt, int arr[], int size) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < tgt) {
            low = mid + 1;
        } else if (arr[mid] > tgt) {
            high = mid - 1;
        } else {
            return mid;
        }

        if (arr[low] == tgt) return low;
        if (arr[high] == tgt) return high;
    }
    return -1;
}

int main () {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(array) / sizeof(array[0]);


    int result = binarySearch(13, array, size);
    printf("Index of target: %d\n", result);

    result = binarySearch(1, array, size);
    printf("Index of target: %d\n", result);

    result = binarySearch(8, array, size);
    printf("Index of target: %d\n", result);

    result = binarySearch(19, array, size);
    printf("Index of target: %d\n", result);

    result = binarySearch(28, array, size);
    printf("Index of target: %d\n", result);


    return 0;
}
