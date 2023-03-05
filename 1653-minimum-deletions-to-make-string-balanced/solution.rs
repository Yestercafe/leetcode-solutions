use std::cmp::min;

impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let n = s.len();
        let s: Vec<char> = s.chars().collect();
        let mut pb = vec![0; n + 1];
        let mut sa = vec![0; n + 1];
        for i in 0..n {
            pb[i + 1] = pb[i];
            if s[i] == 'b' {
                pb[i + 1] += 1;
            }
            sa[n - i - 1] = sa[n - i];
            if s[n - i - 1] == 'a' {
                sa[n - i - 1] += 1;
            }
        }
        
        let mut ans = std::i32::MAX;
        for i in 0..n {
            ans = min(ans, pb[i] + sa[i + 1]);
       }
       return ans;
    }
}

