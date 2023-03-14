impl Solution {
    pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut conn = vec![vec![false; n]; n];
        let mut cnt = vec![0; n];
        for r in &roads {
            conn[r[0] as usize][r[1] as usize] = true;
            conn[r[1] as usize][r[0] as usize] = true;
            cnt[r[0] as usize] += 1;
            cnt[r[1] as usize] += 1;
        }
        let mut max = 0;
        for i in 0..n {
            for j in i+1..n {
                let mut d = cnt[i] + cnt[j];
                if (conn[i][j]) {
                    d -= 1;
                }
                max = max.max(d);
            }
        }

        return max;
    }
}

