package main

import "fmt"

func binarySearch (tgt int32, arr []int32) int32 {
    var low, mid, high int32 = 0, 0, int32(len(arr) - 1)

    for low <= high {
        mid = low + (high - low) / 2
        if arr[mid] < tgt {
            low = mid + 1
        } else if arr[mid] > tgt {
            high = mid - 1
        } else {
            return int32(mid)
        }
    }
    return -1
}

func main () {
    arr := []int32{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}

    var tgt int32 = 4
    var index int32 = binarySearch(tgt, arr)

    fmt.Printf("Target (%d) found at index: %d", tgt, index)
}
