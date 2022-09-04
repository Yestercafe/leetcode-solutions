class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat.front().size();
        for (int i = 0; i < n; ++i) {
            int posI = -1, posJ = -1;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j]) {
                    if (posI < 0) {
                        posI = i;
                        posJ = j;
                    } else {
                        posI = n;
                        break;
                    }
                }
            }
            if (posI < 0 || posI >= n) continue;
            bool flag = true;
            for (int ii = 0; ii < n; ++ii) {
                if (ii == posI) continue;
                if (mat[ii][posJ]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
        return ans;
    }
};

