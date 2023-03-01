use std::cmp::max;

fn max3(a: i32, b: i32, c: i32) -> i32 {
    max(a, max(b, c))
}

impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        let mut ans = vec![vec![0; n - 2]; n - 2];
        for r in 0..n-2 {
            let mut mq: Vec<Vec<usize>> = vec![vec![], vec![], vec![]];

            for offset in 0..3 as usize {
                for i in 0..2 as usize {
                    while mq[offset].len() > 0 && 
                        grid[r + offset][mq[offset].last().unwrap().clone()] < grid[r + offset][i]
                    {
                        mq[offset].pop();
                    }
                    mq[offset].push(i);
                }
            }
            
            for i in 2..n {
                for offset in 0..3 as usize {
                    while mq[offset].len() > 0 && 
                        grid[r + offset][mq[offset].last().unwrap().clone()] < grid[r + offset][i]
                    {
                        mq[offset].pop();
                    }
                    while mq[offset].len() > 0 && i - mq[offset][0] >= 3 {
                        mq[offset].remove(0);
                    }
                    mq[offset].push(i);
                }
                ans[r][i - 2] = max3(grid[r][mq[0][0]], grid[r + 1][mq[1][0]], grid[r + 2][mq[2][0]]);
            }
        }
        ans
    }
}

