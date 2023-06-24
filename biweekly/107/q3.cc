class Solution {
    static constexpr int inf = 0x3f3f3f3f;
    long long min1(long long a, long long b, long long c) {
        if (a <= b && a <= c) return a;
        if (b <= a && b <= c) return b;
        return c;
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector dp(26, vector(26, inf));
        int f = words[0].front() - 'a', b = words[0].back() - 'a';
        dp[f][b] = words[0].size();
        int n = words.size();
        for (int i = 1; i < n; ++i) {
            int wf = words[i].front() - 'a', wb = words[i].back() - 'a';
            vector ndp(26, vector(26, inf));
            for (int f = 0; f < 26; ++f) {
                for (int b = 0; b < 26; ++b) {
                    // prefix
                    if (f == wb) {
                        ndp[wf][b] = min1(ndp[wf][b], dp[f][b] + words[i].size() - 1, inf);
                    } else {
                        ndp[wf][b] = min1(ndp[wf][b], dp[f][b] + words[i].size(), inf);
                    }
                    // suffix
                    if (b == wf) {
                        ndp[f][wb] = min1(ndp[f][wb], dp[f][b] + words[i].size() - 1, inf);
                    } else {
                        ndp[f][wb] = min1(ndp[f][wb], dp[f][b] + words[i].size(), inf);
                    }
                }
            }
            dp.swap(ndp);
        }
        
        int ans = INT_MAX;
        for (int b = 0; b < 26; ++b) {
            ans = min(ans, dp[words.back().front() - 'a'][b]);
        }
        for (int f = 0; f < 26; ++f) {
            ans = min(ans, dp[f][words.back().back() - 'a']);
        }
        return ans;
    }
};

