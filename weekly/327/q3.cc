class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (auto c : word1) ++m1[c];
        for (auto c : word2) ++m2[c];

        for (auto [x, c] : m1) {
            for (auto [y, d] : m2) {
                if (x == y) {
                    if (m1.size() == m2.size())
                        return true;
                } else if (m1.size() - (c == 1) + (m1.find(y) == m1.end()) == m2.size() - (d == 1) + (m2.find(x) == m2.end()))
                    return true;
            }
        }
        return false;
    }
};
