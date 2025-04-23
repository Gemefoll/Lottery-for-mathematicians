use num_bigint::BigInt;
use std::io;

fn step(a: &mut BigInt) {
    if !a.bit(0) {
        *a = a.checked_div(&BigInt::from(2)).unwrap();
    } else {
        *a = (*a).clone() + (*a).clone() + (*a).clone();
        *a += BigInt::from(1);
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("Failed to read line");
    let mut a = BigInt::parse_bytes(s.trim().as_bytes(), 10).expect("Failed to parse BigInt");
    let mut b = a.clone();
    step(&mut b);
    while b != a {
        step(&mut a);
        step(&mut b);
        step(&mut b);
    }
    println!("{a}");
}
