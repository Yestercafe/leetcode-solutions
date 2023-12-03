class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int cnt[26] {};
        for (char c : s1) {
            ++cnt[c - 'a'];
        }
        for (char c : s2) {
            int x = c - 'a';
            --cnt[x];
            if (cnt[x] < 0) return false;
        }
        return true;
    }
};

