class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        int t = n / gcd(n, b);
        auto ms = s;
        for (int i = 0; i < t; ++i) {
            int fa = 0;
            for (int f = 1; f < 10; ++f) {
                int nxt = ((s[1] - '0') + f * a) % 10;
                if (nxt < ((s[1] - '0') + fa * a) % 10) {
                    fa = f;
                }
            }
            if (fa != 0) {
                for (int i = 1; i < n; i += 2) {
                    s[i] = ((s[i] - '0') + fa * a) % 10 + '0';
                }
            }

            if (b % 2) {
                int fa = 0;
                for (int f = 1; f < 10; ++f) {
                    int nxt = ((s[0] - '0') + f * a) % 10;
                    if (nxt < ((s[0] - '0') + fa * a) % 10) {
                        fa = f;
                    }
                }
                if (fa != 0) {
                    for (int i = 0; i < n; i += 2) {
                        s[i] = ((s[i] - '0') + fa * a) % 10 + '0';
                    }
                }
            }

            cout << s << endl;
            ms = min(ms, s);
            s = s.substr(b, n - b) + s.substr(0, b);
        }
        return ms;
    }
};

