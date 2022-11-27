class Solution {
public:
    int appendCharacters(string s, string t) {
        int ps = 0, pt = 0;
        while (pt < t.length() && ps < s.length()) {
            while (ps < s.length() && s[ps] != t[pt]) {
                ++ps;
            }
            if (ps < s.length()) {
                ++ps;
                ++pt;
            }
        }
        
        return t.length() - pt;
    }
};
