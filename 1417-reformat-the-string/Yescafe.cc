class Solution {
    static int abs(int a) { return a < 0 ? -a : a; }
public:
    string reformat(string s) {
        int a = 0, n = 0;
        auto N = s.size();
        for (auto& c : s) {
            if (isalpha(c)) ++a;
            else ++n;
        }
        if (Solution::abs(a - n) > 1) return {};
        if (a >= n) {
            for (int l = 0, r = 1; l < N && r < N; l += 2, r += 2) {
                while (l < N && isalpha(s[l])) l += 2;
                while (r < N && !isalpha(s[r])) r += 2;
                if (l >= N || r >= N) break;
                swap(s[l], s[r]);
            }
        } else {
            for (int l = 0, r = 1; l < N && r < N; l += 2, r += 2) {
                while (l < N && !isalpha(s[l])) l += 2;
                while (r < N && isalpha(s[r])) r += 2;
                if (l >= N || r >= N) break;
                swap(s[l], s[r]);
            }
        }
        return s;
    }
};

