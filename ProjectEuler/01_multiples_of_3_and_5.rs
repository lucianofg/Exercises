// Find the sum of all the multiples of 3 or 5 below 1000
// Taken from https://projecteuler.net/problem=1

fn main() {
    let mut result = 0;
    let mut i = 1;

    loop {
        if i > 1000 {
            break;
        } else if i % 3 == 0 || i % 5 == 0 {
            result += i;
        }
        i += 1;
    }

    println!("{}", result);
}

