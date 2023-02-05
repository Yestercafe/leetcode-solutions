class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, int> m, m1, m2;
        for (auto a : b1) ++m[a], ++m1[a];
        for (auto a : b2) ++m[a], ++m2[a];      
        for (auto& [_, s] : m) {
            if (s % 2) return -1ll;
        }
        
        vector<int> dq1, dq2;
        for (auto [f, s] : m) {
            int has = m1[f];
            int diff = s / 2 - has;
            if (diff > 0) {
                for (int i = 0; i < diff; ++i)
                    dq1.push_back(f);
            } else if (diff < 0) {
                for (int i = 0; i < -diff; ++i)
                    dq2.push_back(f);
            }
        }
        int need = dq1.size();
        long long ans1 = 0, ans2 = 0;
        int minn = m.begin()->first;
        cout << "need = " << need / 2 << endl;
        for (int i = 0; i < need; ++i) {
            ans1 += min(2 * minn, min(dq1[i], dq2[need - 1 - i]));
        }
        for (int i = 0; i < need; ++i) {
            ans2 += min(2 * minn, min(dq2[i], dq1[need - 1 - i]));
        }
        cout << ans1 << " " << ans2 << endl;
        return min(ans1, ans2);
        
    }
};

