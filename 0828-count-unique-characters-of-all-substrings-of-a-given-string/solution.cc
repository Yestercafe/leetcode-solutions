class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> m(26, {-1});
        for (int i = 0; i < s.length(); ++i) {
            m[s[i] - 'A'].push_back(i);
        }

        int ans = 0;
        for (auto& v : m) {
            if (v.size() < 2) continue;
            v.push_back(s.length());
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += (v[i + 1] - v[i]) * (v[i] - v[i - 1]);
            }
        }
        
        return ans;
    }
};

