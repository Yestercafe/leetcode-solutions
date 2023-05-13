class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n);
        int q = queries.size();
        vector<int> ans(q);

        auto left = [&](int i) -> int {
            if (i - 1 < 0) return color[i] == 0 ? 1 : 0;
            return color[i - 1] == color[i];
        };
        auto right = [&](int i) -> int {
            if (i + 1 >= n) return color[i] == 0 ? 1 : 0;
            return color[i] == color[i + 1];
        };

        for (int i = 0; i < q; ++i) {
            int idx = queries[i][0], c = queries[i][1];
            if (i != 0) ans[i] = ans[i - 1];
            if (color[idx] != 0)
                ans[i] -= left(idx) + right(idx);
            color[idx] = c;
            ans[i] += left(idx) + right(idx);
        }

        return ans;
    }
};

