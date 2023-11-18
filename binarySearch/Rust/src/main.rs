#[allow(non_snake_case)]
fn binary_search(tgt: i32, arr: [i32; 20]) -> i32 {
    let mut low: i32 = 0;
    let mut high: i32 = arr.len() as i32;
    let mut mid: i32;

    while low <= high {
        mid = low + (high - low) / 2;
        if arr[mid as usize] > tgt {
            high = mid - 1;
        } else if arr[mid as usize] < tgt {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}


fn main() {
    let arr: [i32; 20] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
    let tgt: i32 = 8;

    let index: i32 = binary_search(tgt, arr);

    println!("Target ({}) was found at index {}", tgt, index);
}
