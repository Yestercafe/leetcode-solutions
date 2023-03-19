kjclass Solution {
public:
    vector<int> evenOddBit(int n) {
        vector ans(2, 0);
        int i = 0;
        int cnt = 0;
        while (n != 0) {
            if (n % 2) ++ans[i];
            i = 1 - i;
            ++cnt;
            n /= 2;
        }
        // cout << cnt << endl;
        // if (cnt % 2) swap(ans[0], ans[1]);
        return ans;
    }
};

