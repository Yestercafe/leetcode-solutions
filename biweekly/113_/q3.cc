class Solution {
public:
    int countPairs(vector<vector<int>>& cs, int k) {
        auto dis = [](vector<int>& a, vector<int>& b) {
            return (a[0] ^ b[0]) + (a[1] ^ b[1]);
        };

        int ans = 0;
        map<pair<int, int>, int> cnt;

        for (auto& c : cs) {
            int x1 = c[0], y1 = c[1];

            for (int xx = 0; xx <= k; ++xx) {
                int xy = k - xx;
                int x2 = (x1 ^ xx), y2 = (y1 ^ xy);

                if (auto fnd = cnt.find(make_pair(x2, y2)); fnd != cnt.end()) {
                    ans += fnd->second;
                }
            }

            ++cnt[make_pair(x1, y1)];
        }

        return ans;
    }
};
