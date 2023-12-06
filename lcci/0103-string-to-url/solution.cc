class Solution {
public:
    string replaceSpaces(string s, int length) {
        int space_cnt {};
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ')
                ++space_cnt;
        }
        int shift = space_cnt * 2;
        s.erase(s.begin() + length + shift, s.end());
        for (int i = length - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                s[shift + i] = s[i];
                continue;
            }
            s[shift-- + i] = '0';
            s[shift-- + i] = '2';
            s[shift + i] = '%';
        }
        return s;
    }
};

