class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxx = -1, ans = -1;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            if (maxx < cnt) {
                maxx = cnt;
                ans = i;
            }
        }
        return {ans, maxx};
    }
};

