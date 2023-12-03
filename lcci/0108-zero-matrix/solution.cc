class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> row(n), col(m);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (matrix[r][c] == 0) {
                    row[r] = true;
                    col[c] = true;
                }
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (row[r] || col[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};

