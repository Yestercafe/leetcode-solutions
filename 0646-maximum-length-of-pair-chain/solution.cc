class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        int cnt = 0;
        int p = pairs.front()[0] - 1;
        for (auto& pr : pairs) {
            if (pr[0] <= p) continue;
            ++cnt;
            p = pr[1];
        }
        return cnt;
    }
};

