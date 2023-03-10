use std::collections::HashMap;
use std::cmp::min;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let mut sum = 0;
        for i in &nums {
            sum = (sum + i) % p;
        }
        if sum == 0 {
            return 0;
        }

        let n = nums.len();
        let mut map = HashMap::new();
        map.insert(0, -1);
        let mut pref = 0;
        let mut ans = n as i32;
        for i in 0..n {
            pref = (pref + nums[i]) % p;
            if let Some(pi) = map.get(&((pref + p - sum) % p)) {
                ans = min(ans, i as i32 - pi);
            }
            map.insert(pref, i as i32);
        }
        if ans == n as i32 {
            -1
        } else {
            ans
        }
    }
}

