// Find the sum of all the multiples of 3 or 5 below 1000
// Taken from https://projecteuler.net/problem=1

fn calc(max: i32, sum: i32) -> i32 {
    if max == 1 {
        sum
    } else {
        if max % 3 == 0 || max % 5 == 0 {
            calc(max -1, sum + max)
        } else {
            calc(max - 1, sum)
        }
    }
}

fn main() {
    let result = calc(1000, 0);
    println!("{}", result);
}

