class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for (auto a : nums) {
            auto s = to_string(a);
            for (auto ch : s) {
                ans.push_back(ch - '0');
            }
        }
        
        return ans;
    }
};

