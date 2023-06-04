class Solution {
    using i64 = long long;
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        i64 ans = 0;
        std::set<int> sr, sc;
        for (int i = queries.size() - 1; i >= 0; --i) {
            auto& q = queries[i];
            int ty = q[0], idx = q[1], val = q[2];
            if (ty == 0) {
                if (sr.count(idx)) continue;
                ans += 1LL * (n - sc.size()) * val;
                sr.insert(idx);
            } else {
                if (sc.count(idx)) continue;
                ans += 1LL * (n - sr.size()) * val;
                sc.insert(idx);
            }
        }
        return ans;
    }
};

