class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int, int>> p(26, {-1, -1});
        for (int i = 0; i < s.length(); ++i) {
            if (p[s[i] - 'a'].first == -1) {
                p[s[i] - 'a'].first = i;
            } else {
                p[s[i] - 'a'].second = i;
            }
        }

        int m = 0;
        for (auto& [s, e] : p) {
            if (e != -1) {
                m = max(m, e - s);
            }
        }

        return m - 1;
    }
};

