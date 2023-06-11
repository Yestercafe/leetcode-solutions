class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& a1, vector<int>& a2, vector<vector<int>>& qs) {
        int nc = a1.size(), nq = qs.size();
        vector<pair<int, int>> cs(nc);
        for (int i = 0; i < nc; ++i) {
            cs[i].first = a1[i], cs[i].second = a2[i];
        }
        vector<array<int, 3>> qis(nq);
        for (int i = 0; i < nq; ++i) {
            qis[i][0] = qs[i][0], qis[i][1] = qs[i][1], qis[i][2] = i;
        }
        sort(cs.begin(), cs.end(), greater<>{});
        sort(qis.begin(), qis.end(), greater<>{});

        vector<int> ans(nq, -1);
        vector<pair<int, int>> ms;     // List (Y, X + Y)
        auto msPush = [&](int y, int xy) {
            while (ms.size() && ms.back().second <= xy) {
                ms.pop_back();
            }
            if (ms.empty() || ms.back().first < y) {
                ms.push_back({y, xy});
            }
        };
        int ci = 0;
        for (int qi = 0; qi < nq; ++qi) {
            int x = qis[qi][0], y = qis[qi][1], idx = qis[qi][2];
            while (ci < nc && cs[ci].first >= x) {
                msPush(cs[ci].second, cs[ci].first + cs[ci].second);
                ++ci;
            }
            if (ms.size()) {
                auto fnd = lower_bound(ms.begin(), ms.end(), make_pair(y, -1));
                if (fnd != ms.end())
                    ans[idx] = fnd->second;
            }
        }
        return ans;
    }
};

