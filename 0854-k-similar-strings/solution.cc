class Solution {
    int ans = 1234567;
    int len;
    int aux(string& s1, string& s2, int idx, int cnt) {
        if (cnt >= ans)
            return ans;
        if (idx == len - 1)
            return ans = min(cnt, ans);
        
        for (int i = idx; i < len; ++i) {
            if (s1[i] != s2[i]) {
                for (int j = i + 1; j < len; ++j) {
                    if (s1[i] == s2[j] && s2[j] != s1[j]) {
                        swap(s2[i], s2[j]);
                        aux(s1, s2, i + 1, cnt + 1);
                        swap(s2[i], s2[j]);
                        if (s1[j] == s2[i]) break;
                    }
                }
                return ans;
            }
        }
        return ans = min(cnt, ans);
    }
public:
    int kSimilarity(string s1, string s2) {
        len = s1.length();
        return aux(s1, s2, 0, 0);
    }
};

