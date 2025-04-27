use num_bigint::BigUint;
use std::io;

fn step(a: &mut BigUint) {
    *a *= 3u32;
    *a += 1u32;
    *a >>= a.trailing_zeros().unwrap_or(0);
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("Failed to read line");
    let mut a = BigUint::parse_bytes(s.trim().as_bytes(), 10).expect("Failed to parse BigInt");
    a >>= a.trailing_zeros().unwrap_or(0);
    let mut b = a.clone();
    step(&mut b);
    while b != a {
        step(&mut a);
        step(&mut b);
        step(&mut b);
    }
    println!("{a}");
}
