class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int f = 1;
        sort(coins.begin(), coins.end());
        for (auto c : coins) {
            if (f < c) break;
            f += c;
        }
        return f;
    }
};

