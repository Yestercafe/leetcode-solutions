class Solution {
public:
    int maximumCount(vector<int>& nums) {
        return max(count_if(nums.begin(), nums.end(), [](const int& x) { return x > 0; }), count_if(nums.begin(), nums.end(), [](const int& x) { return x < 0; }));
    }
};