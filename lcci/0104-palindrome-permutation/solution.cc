class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnt;
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }

        bool has_odd = false;
        for (auto [_, c] : cnt) {
            if (c % 2) {
                if (has_odd) return false;
                has_odd = true;
            }
        }
        return true;
    }
};

