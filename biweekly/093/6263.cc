class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        for (int i = 0; i + 2 < n; i += 2) {
            ans = max(ans, stones[i + 2] - stones[i]);
        }
        ans = max(ans, stones[n - 1] - stones[n - 2]);
        for (int i = 1; i + 2 < n; i += 2) {
            ans = max(ans, stones[i + 2] - stones[i]);
        }
        ans = max({ans, stones[1] - stones[0], stones[n - 1] - stones[n - 2]});
        return ans;
    }
};

