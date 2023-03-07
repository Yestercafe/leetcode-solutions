impl Solution {
    pub fn max_value(f: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (f.len(), f[0].len());
        let mut f = f;
        for i in 0..n {
            for j in 0..m {
                if i == 0 && j == 0 {
                    continue;
                } else if j == 0 {
                    f[i][j] += f[i - 1][j];
                } else if i == 0 {
                    f[i][j] += f[i][j - 1];
                } else {
                    f[i][j] += std::cmp::max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[n - 1][m - 1];
    }
}

