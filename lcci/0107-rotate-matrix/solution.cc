class Solution {
    // a -> b -> c -> d -> a
    static void cycle4(int& a, int& b, int& c, int& d) {
        int tmp = d;
        d = c;
        c = b;
        b = a;
        a = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                cycle4(
                    matrix[i][j],
                    matrix[j][n - 1 - i],
                    matrix[n - 1 - i][n - 1 - j],
                    matrix[n - 1 - j][i]
                );
            }
        }
    }
};

