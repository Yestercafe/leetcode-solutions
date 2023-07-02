class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            set<int> si, sa;
            auto getMax = [&]() {
                return -*sa.begin();
            };
            auto getMin = [&]() {
                return *si.begin();
            };
            auto insert = [&](int x) {
                si.insert(x);
                sa.insert(-x);
            };
            int c = 0;
            for (int j = i; j < n; ++j) {
                int a = nums[j];
                
                if (!si.empty() && !si.count(a)) {
                    if (a < getMin()) {
                        ++c;
                        if (si.count(a + 1)) --c;
                    } else if (a > getMax()) {
                        ++c;
                        if (sa.count(1 - a)) --c;
                    } else {
                        ++c;
                        if (si.count(a - 1)) --c;
                        if (si.count(a + 1)) --c;
                    }
                }

                ans += c;
                insert(a);
            }
        }

        return ans;
    }
};

