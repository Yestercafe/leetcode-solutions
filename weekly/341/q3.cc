class Solution {
public:
    int addMinimum(string word) {
        char prev = 'a' - 1;
        int con = 0;
        int ans = 0;
        for (char c : word) {
            if (c > prev) {
                ++con;
                prev = c;
            } else {
                ans += 3 - con;
                con = 1;
                prev = c;
            }
        }
        
        if (con) ans += 3 - con;
        
        return ans;
    }
};

