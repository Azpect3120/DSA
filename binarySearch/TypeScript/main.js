function binarySearch(tgt, arr) {
    var low, mid, high;
    low = 0, high = arr.length - 1;
    while (low <= high) {
        mid = Math.floor(low + (high - low) / 2);
        if (arr[mid] < tgt) {
            low = mid + 1;
        }
        else if (arr[mid] > tgt) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
var array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
var target = 13;
var index = binarySearch(target, array);
console.log("Target (".concat(target, ") was found at index: ").concat(index));
