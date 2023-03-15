use std::collections::HashMap;

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut ans = 1;
        let mut map = HashMap::new();
        let (mut gr_cnt, mut le_cnt) = (0, 0);

        let mut pk = n;
        for i in 0..n {
            if nums[i] == k {
                pk = i;
                break
            }
        }
        for d in 1..pk+1 {
            if nums[pk - d] < k {
                le_cnt += 1
            } else {
                gr_cnt += 1
            }
            if le_cnt == gr_cnt || le_cnt + 1 == gr_cnt {
                ans += 1;
            }
            if let Some(v) = map.get(&(gr_cnt - le_cnt)) {
                map.insert(gr_cnt - le_cnt, v + 1);
            } else {
                map.insert(gr_cnt - le_cnt, 1);
            }
        }
        println!("{} {:?}", ans, map);
        let (mut gr_cnt, mut le_cnt) = (0, 0);
        for d in 1..n - pk {
            if nums[pk + d] < k {
                le_cnt += 1;
            } else {
                gr_cnt += 1;
            }
            if le_cnt == gr_cnt || le_cnt + 1 == gr_cnt {
                ans += 1;
            }
            ans += map.get(&(le_cnt - gr_cnt)).unwrap_or(&0) + map.get(&(le_cnt - gr_cnt + 1)).unwrap_or(&0);
        }

        ans
    }
}

