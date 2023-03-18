class Solution {
    using i64 = long long;
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> inums;
        for (int i = 0; i < n; ++i) {
            inums.emplace_back(nums[i], i);
        }
        sort(inums.begin(), inums.end());
        
        vector<bool> vis(n);
        i64 score = 0;
        for (int i = 0; i < n; ++i) {
            int snd = inums[i].second;
            if (vis[snd]) continue;
            vis[snd] = true;
            if (snd - 1 >= 0) vis[snd - 1] = true;
            if (snd + 1 < n) vis[snd + 1] = true;
            // cout << inums[i].first << ' ' << snd << endl;
            score += inums[i].first;
        }
        return score;
    }
};

