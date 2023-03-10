class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> m;
        m.emplace(0, -1);
        int pref = 0;
        int ans = -1, pos = -1;
        for (int i = 0; i < n; ++i) {
            auto& s = array[i];
            if (isalpha(s[0])) ++pref;
            else --pref;
            if (auto fnd = m.find(pref); fnd != m.end()) {
                if (ans < i - fnd->second) {
                    ans = i - fnd->second;
                    pos = fnd->second + 1;
                }
            } else {
                m.emplace(pref, i);
            }
        }
        if (ans < 0) return {};
        return {array.begin() + pos, array.begin() + pos + ans};
    }
};

