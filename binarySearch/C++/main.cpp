#include <iostream>

int binarySearch (int tgt, int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] < tgt) {
            low = mid + 1;
        } else if (arr[mid] > tgt) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main () {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int target = 8;
    int size = sizeof(array) / sizeof(array[0]);

    int index = binarySearch(target, array, size);

    std::cout << "Target (" << target << ") found at index: " << index << std::endl;

    return 0;
}
