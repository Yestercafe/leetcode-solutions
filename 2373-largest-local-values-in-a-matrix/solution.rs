use std::cmp::max;

impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        let mut ans = vec![vec![0; n - 2]; n - 2];
        for r in 0..n-2 {
            for c in 0..n-2 {
                for i in 0..3 as usize {
                    for j in 0..3 as usize {
                        ans[r][c] = max(ans[r][c], grid[r + i][c + j]);
                    }
                }
            }
        }
        ans
    }
}

