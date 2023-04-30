class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int, int>> c;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                c[mat[i][j]] = make_pair(i, j);
            }
        }
        vector<int> cc(n), cr(m);
        for (int i = 0; i < n * m; ++i) {
            auto [x, y] = c[arr[i]];
            ++cc[x];
            if (cc[x] == m) return i;
            ++cr[y];
            if (cr[y] == n) return i;
        }
        return -1;
    }
};

