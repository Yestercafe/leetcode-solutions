class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<int, int> flag_cnt;
        for (auto& s : words) {
            unsigned flag = 0;
            for (auto& c : s) {
                flag |= (1) << (c - 'a');
            }
            ++flag_cnt[flag];
        }
        return accumulate(flag_cnt.begin(), flag_cnt.end(), 0, [](int s, pair<int, int> n) { return s + n.second * (n.second - 1) / 2; });
    }
};

