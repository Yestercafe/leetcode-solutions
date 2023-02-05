class Solution {
public:
    int maxCount(vector<int>& bd, int n, int ms) {
        unordered_set<int> s(bd.begin(), bd.end());
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.find(i) != s.end()) continue;
            if (i + sum > ms) break;
            ++ans;
            sum += i;
        }
        return ans;
    }
};

