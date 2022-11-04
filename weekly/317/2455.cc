class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, c = 0;
        for (auto& a : nums) {
            if (a % 6) continue;
            sum += a;
            c++;
        }
        if (c == 0) return 0;
        return sum / c;
    }
};

