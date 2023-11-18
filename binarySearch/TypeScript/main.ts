function binarySearch (tgt: number, arr: number[]): number {
    let low: number, mid: number, high: number;
    low = 0, high = arr.length - 1;

    while (low <= high) {
        mid = Math.floor(low + (high - low) / 2);
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

const array: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
const target: number = 13;

const index: number = binarySearch(target, array);

console.log(`Target (${target}) was found at index: ${index}`);
