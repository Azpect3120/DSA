def binarySearch(tgt: int, arr: list) -> int:
    low, mid, high = 0, 0, len(arr) - 1

    while (low <= high):
        mid = low + (high - low) // 2
        if (arr[mid] < tgt):
            low = mid + 1
        elif (arr[mid] > tgt):
            high = mid - 1
        else:
            return mid
    return -1


array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
target = 2

index = binarySearch(target, array)

print("Target (" + str(target) + ") found at index: " + str(index))
