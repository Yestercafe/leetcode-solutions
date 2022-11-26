class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.length() + 1;
        vector<int> prefix(n);
        int sum = 0;
        prefix[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (c[i - 1] == 'Y') {
                ++sum;
            }
            prefix[i] = sum;
        }
        
        int minn = prefix[n - 1];
        int minp = 0;
        int res = minn;
        // cout << "default " << minn << endl;
        for (int i = 1; i < n; ++i) {
            res -= (c[i - 1] == 'Y' ? 1 : 0);
            auto r = res + (i - prefix[i]);
            if (minn > r) {
                // cout << "i = " << i << ", r = " << r << endl;
                minn = r;
                minp = i;
            }
        }
        
        return minp;
    }
};

