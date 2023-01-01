class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        long long d = 0;
        for (auto a : s) {
            a -= '0';
            if (a > k) return -1;
            if (d * 10 + a > k) {
                ++ans;
                d = 0;
            }
            d = d * 10 + a;
        }
        if (d > k) {
            return -1;
        } else {
            cout << d << endl;
            ++ans;
        }
        return ans;
    }
};

