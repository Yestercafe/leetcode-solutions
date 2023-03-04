use std::collections::HashMap;

impl Solution {
    pub fn count_triplets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0 as i32;
        let mut map = HashMap::<i32, i32>::new();
        // 1000 * 1000
        for i in 0..n {
            for j in 0..n {
                let and2 = nums[i] & nums[j];
                if let Some(cnt) = map.get(&and2) {
                    map.insert(and2, cnt + 1);
                } else {
                    map.insert(and2, 1);
                }
            }
        }
        // log(1000) * 1000
        for (x, cnt) in &map {
            for i in 0..n {
                if (nums[i] & x == 0) {
                    ans += cnt;
                }
            }
        }
        return ans;
    }
}

