class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for (auto& p : points) {
            s.insert(p[0]);
        }
        vector<int> v(s.begin(), s.end());
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, v[i + 1] - v[i]);
        }
        return ans;
    }
};

