class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int n = r1.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = r1[i] - r2[i];
            v[i].second = i;
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>{});
        int i;
        int ans = 0;
        for (i = 0; i < k; ++i) {
            ans += r1[v[i].second];
        }
        for (; i < n; ++i) {
            ans += r2[v[i].second];
        }
        return ans;
    }
};

