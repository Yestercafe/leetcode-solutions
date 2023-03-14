impl Solution {
    pub fn restore_matrix(row_sum: Vec<i32>, col_sum: Vec<i32>) -> Vec<Vec<i32>> {
        let mut row_sum = row_sum;
        let mut col_sum = col_sum;
        let (n, m) = (row_sum.len(), col_sum.len());
        let mut mat = vec![vec![0; m]; n];
        let (mut i, mut j) = (0usize, 0usize);
        while i != n && j != m {
            if row_sum[i] < col_sum[j] {
                mat[i][j] = row_sum[i];
                col_sum[j] -= row_sum[i];
                row_sum[i] = 0;
                i += 1;
            } else {
                mat[i][j] = col_sum[j];
                row_sum[i] -= col_sum[j];
                col_sum[j] = 0;
                j += 1;
            }
        }

        return mat;
    }
}

