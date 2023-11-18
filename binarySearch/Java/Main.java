public class Main {
    public static int BinarySearch (int tgt, int[] arr) {
        int low = 0, mid = 0, high = arr.length;

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

    public static void main (String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        int target = 17;

        int index = BinarySearch(target, array);
        System.out.println("Target (" + target + ") was found at index: " + index);
    }
}
