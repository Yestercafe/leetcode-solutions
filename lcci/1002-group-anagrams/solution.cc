class Solution {
    constexpr const static int MOD = 1e9 + 7;
    array<int, 26> prime {
         2,  3,  5,  7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<int, int>> enc(n, {1, 0});
        for (int i = 0; i < n; ++i) {
            enc[i].second = i;
            for (char c : strs[i]) {
                enc[i].first = (1LL * enc[i].first * prime[c - 'a']) % MOD;
            }
        }
        ranges::sort(enc);

        int prev = -1;
        vector<vector<string>> ans;
        for (auto [enci, i] : enc) {
            if (prev != enci) {
                ans.push_back({});
                prev = enci;
            }
            ans.back().push_back(strs[i]);
        }
        return ans;
    }
};

