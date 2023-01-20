class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            s1 += a;
            while (a != 0) {
                s2 += a % 10;
                a /= 10;
            }
        }
        return abs(s1 - s2);
    }
};
