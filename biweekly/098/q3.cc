class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        for (int a = 1; a <= INT_MAX; a *= 2) {
            if (s.find(a) == s.end()) {
                return a;
            }
        }
        
        return 0;
    }
};

