class Solution {
public:
    int maxScore(string s) {
        int score = count(s.begin(), s.end(), '1');
        int ans = 0;
        int N = s.length();
        for (int i = 0; i < N - 1; ++i) {
            switch (s[i]) {
                case '0': ++score; break;
                case '1': --score; break;
            }
            ans = max(ans, score);
        }
    return ans;
    }
};

