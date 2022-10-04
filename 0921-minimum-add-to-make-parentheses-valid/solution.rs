impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let s: Vec<char> = s.chars().collect();
        
        let mut left = 0;
        let mut right = 0;
        
        for c in s {
            if c == '(' {
                right += 1;
            } else {
                right -= 1;
                if right < 0 {
                    left -= right;
                    right = 0;
                }
            }
        }
        
        left + right
    }
}

