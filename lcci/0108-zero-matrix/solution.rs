impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let nrow = matrix.len();
        let ncol = matrix[0].len();
        let mut rows: Vec<bool> = vec![false; nrow];
        let mut cols: Vec<bool> = vec![false; ncol];
        
        for i in 0..nrow {
            for j in 0..ncol {
                if matrix[i][j] == 0 {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        
        for i in 0..nrow {
            for j in 0..ncol {
                if rows[i] || cols[j] {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

