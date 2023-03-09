impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let mut w_cnt = 0;
        let k = k as usize;
        let blocks: Vec<char> = blocks.chars().collect();
        for i in 0..k {
            if blocks[i] == 'W' {
                w_cnt += 1
            }
        }
        let mut min = w_cnt;
        if min == 0 {
            return 0;
        }
        let n = blocks.len();
        for i in k..n {
            if blocks[i - k] == 'W' {
                w_cnt -= 1;
            }
            if blocks[i] == 'W' {
                w_cnt += 1;
            }
            min = std::cmp::min(min, w_cnt);
            if min == 0 {
                return 0;
            }
        }
        return min;
    }
}

