class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        if (s == "a") return "z";
        if (all_of(s.begin(), s.end(), [](char a) { return a == 'a'; })) {
            s.back() = 'z';
            return s;
        }
        int start = 0;
        int i = 0;
        while (s[i++] == 'a') start = i;
        for (int i = start; i < n; ++i) {
            if (s[i] == 'a') {
                break;
            }
            s[i]--;
        }
        return s;
    }
};

