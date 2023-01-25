class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });

        vector<int> ans;
        for (auto& q: queries) {
            int x = q[0], y = q[1], r = q[2];
            int cnt {};
            for (
                auto itr = upper_bound(points.begin(), points.end(), x - r - 1, [](const int a, const auto& b) { return a < b[0]; });
                itr != lower_bound(points.begin(), points.end(), x + r + 1, [](const auto& a, const int b) { return a[0] < b; });
                ++itr
            ) {
                auto px = (*itr)[0], py = (*itr)[1];
                if (hypot(px - x, py - y) <= r) {
                    ++cnt;
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};

