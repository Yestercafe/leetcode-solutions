class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> ans(length);
        w /= 32;
        for (int i = y * w; i < (y + 1) * w; ++i) {
            for (int j = 0; j < 32; ++j) {
                int p = j + (i - y * w) * 32;
                if (x1 <= p && p <= x2) {
                    ans[i] |= 1 << (31 - j);
                }
            }
        }
        return ans;
    }
};

