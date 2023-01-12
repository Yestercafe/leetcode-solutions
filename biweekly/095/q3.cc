class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int an = 0;
        for (auto& a : nums) an ^= a;
        return an;
        
        unordered_map<int, int> t1, m;
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {*/
        for (auto& a : nums) {
            for (auto& b : nums) {
                ++t1[a | b];
            }
        }
        
        for (auto& a : nums) {
            for (auto& [val, cnt] : t1) {
                if (cnt % 2 == 0) continue;
                m[a | val] += cnt;
            }
        }
        
        int ans = 0;
        for (auto& [val, cnt] : m) {
            if (cnt & 1) ans ^= val;
        }
        return ans;
    }
};

