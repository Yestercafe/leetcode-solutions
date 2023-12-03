class Solution {
public:
    string compressString(string s) {
        string ans;
        char prev = '-';
        int cnt = 0;
        for (char ch : s) {
            if (prev != ch) {
                if (cnt > 0) {
                    ans.push_back(prev);
                    ans += to_string(cnt);
                }
                prev = ch;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        if (cnt != 0) {
            ans.push_back(prev);
            ans += to_string(cnt);
        }

        return ans.length() < s.length() ? ans : s;
    }
};

