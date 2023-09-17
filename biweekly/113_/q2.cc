class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int maxx = 0;
        map<int, int> cnt;
        for (auto a : nums) {
            maxx = max(maxx, ++cnt[a]);
        }
        
        int n = nums.size();
        if (maxx * 2 <= n) {
            return n & 1;
        } else {
            return 2 * maxx - n;
        }
    }
};
