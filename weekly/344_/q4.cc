#define L(i) ((i) * 2 + 1)
#define R(i) ((i) * 2 + 2)

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            ans += abs(cost[L(i)] - cost[R(i)]);
            cost[i] += max(cost[L(i)], cost[R(i)]);
        }
        return ans;
    }
};

