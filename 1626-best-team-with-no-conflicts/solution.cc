class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> sa(n);
        for (int i = 0; i < n; ++i) {
            sa[i].first = scores[i];
            sa[i].second = ages[i];
        }
        sort(sa.begin(), sa.end());
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            auto [score, age] = sa[i];
            for (int j = 0; j < i; ++j) {
                if (sa[j].second <= age) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += score;
        }
        return *max_element(f.begin(), f.end());
    }
};

