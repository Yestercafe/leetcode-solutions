class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> cnts, cntt;
        for (auto& c : s) ++cnts[c];
        for (auto& c : target) ++cntt[c];
        int ans = 12345678;
        for (auto& [ch, cnt] : cntt) {
            ans = min(ans, cnts[ch] / cnt);
        }
        return ans;
    }
};

