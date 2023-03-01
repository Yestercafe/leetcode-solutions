use std::collections::HashSet;

#[derive(Hash, Eq, PartialEq, Clone)]
struct Frac {
    pub n: i64,
    pub d: i64,
}

impl Frac {
    fn new(n: f64) -> Frac {
        static d: i64 = 10000000;
        Frac {
            n: (n * d as f64) as i64,
            d,
        }
    } 
}

impl Solution {
    pub fn print_bin(num: f64) -> String {
        let mut num = Frac::new(num * 2f64);
        let mut ans = "0.".to_string();
        let mut memo = HashSet::new();
        while num.n != 0 {
            if memo.contains(&num) {
                return "ERROR".into();
            }
            memo.insert(num.clone());
            if num.n >= num.d {
                ans.push('1');
                num.n -= num.d;
            } else {
                ans.push('0');
            }
            num.n *= 2;
        }
        ans
    }
}

