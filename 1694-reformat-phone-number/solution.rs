impl Solution {
    pub fn reformat_number(number: String) -> String {
        let mut s = String::new();
        for c in number.chars() {
            if c.is_digit(10) {
                s.push(c);
            }
        }
        // println!("s = {}", s);
        
        let mut formatted = String::new();
        if s.len() <= 3 {
            s
        } else if s.len() == 4 {
            s.insert(2, '-');
            s
        } else {
            let mut formatted = String::new();
            let nblocks = if s.len() % 3 == 1 {
                s.len() / 3 - 1
            } else {
                s.len() / 3
            };
            let s: Vec<char> = s.chars().collect();
            // println!("{}", nblocks);
            
            for i in 0..nblocks {
                if i != 0 {
                    formatted.push('-');
                }
                for b in 0..3 {
                    // println!("idx = {}", i * 3 + b);
                    formatted.push(s[i * 3 + b]);
                }
            }
            
            let rem = s.len() - nblocks * 3;
            if rem == 2 {
                formatted.push('-');
                for b in 0..2 {
                    formatted.push(s[nblocks * 3 + b]);
                }
            } else if rem == 4 {
                formatted.push('-');
                for b in 0..2 {
                    formatted.push(s[nblocks * 3 + b]);
                }
                formatted.push('-');
                for b in 0..2 {
                    formatted.push(s[nblocks * 3 + 2 + b]);
                }
            }
            formatted
        }
    }
}

