class Solution {
    using ll = long long;
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for (auto a : nums) {
            for (int i = 2; (ll) i * i <= a; ++i) {
                if (a % i == 0) {
                    s.insert(i);
                }
                while (a % i == 0) a /= i;
            }
            if (a != 1) s.insert(a);
        }
        return s.size();
    }
};

