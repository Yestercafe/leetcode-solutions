class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> s;
        const int n = nums.size();
        long long mx = 0, sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            ++s[nums[i]];
        }
        if (s.size() == k) mx = sum;
        
        for (int i = 0; i < n - k; ++i) {
            sum += nums[i + k] - nums[i];
            ++s[nums[i + k]];
            if (--s[nums[i]] == 0) {
                s.erase(nums[i]);
            }
            
            if (s.size() == k) {
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};

