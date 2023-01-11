class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        int n = num.size();
        for (auto& c : num) ++cnt[c - '0'];
        for (int i = 0; i < n; ++i)
            if (num[i] - '0' != cnt[i]) return false;
        return true;
    }
};

