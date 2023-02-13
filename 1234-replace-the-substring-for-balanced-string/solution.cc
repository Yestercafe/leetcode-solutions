class Solution {
    int cnt[4] {};
    int total[4] {};
    int nd4;
    bool valid() {
        bool ret = true;
        for (int i = 0; i < 4; ++i) {
            // cout << total[i] - cnt[i] << ' ';
            ret &= (total[i] - cnt[i] <= nd4);
        }
        // cout << endl;
        return ret;
    }
public:
    int balancedString(string s) {
        unordered_map<char, int> m {
            {'Q', 0}, {'W', 1}, {'E', 2}, {'R', 3},
        };

        for (char c : s) {
            ++total[m[c]];
        }

        int n = s.length();
        nd4 = n / 4;
        int minn = INT_MAX;
        int left = 0;
        if (valid()) return 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[m[s[right]]];
            while (left <= right && valid()) {
                minn = min(minn, right - left + 1);
                --cnt[m[s[left++]]];
            }
        }
        return minn;
    }
};

