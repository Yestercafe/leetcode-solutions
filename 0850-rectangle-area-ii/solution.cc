// 不会，抄的
class Solution {
    static constexpr int MOD = 1e9 + 7;
    struct Sweep {
        int x, i, d;
    };
    using ll = long long;
public:
    int rectangleArea(vector<vector<int>>& rects) {
        int n = rects.size();
        vector<int> hbound;
        for (const auto& r : rects) {
            hbound.push_back(r[1]);
            hbound.push_back(r[3]);
        }
        sort(hbound.begin(), hbound.end());
        hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());
        
        int m = hbound.size();
        vector<int> hseg(m - 1);
        
        vector<Sweep> sweep;
        for (int i = 0; i < n; ++i) {
            sweep.push_back({rects[i][0], i, 1});
            sweep.push_back({rects[i][2], i, -1});
        }
        sort(sweep.begin(), sweep.end(), [](const Sweep& a, const Sweep& b) {
            if (a.x != b.x) return a.x < b.x;
            if (a.i != b.i) return a.i < b.i;
            return a.d < b.d;
        });
        
        ll ans = 0;
        const int sn = sweep.size();
        for (int i = 0; i < sn; ++i) {
            int j = i;
            while (j + 1 < sn && sweep[i].x == sweep[j + 1].x) {
                ++j;
            }
            if (j + 1 == sn) {
                break;
            }
            
            for (int k = i; k <= j; ++k) {
                int idx = sweep[k].i;
                int dif = sweep[k].d;
                int left = rects[idx][1], right = rects[idx][3];
                for (int x = 0; x < m - 1; ++x) {
                    if (left <= hbound[x] && hbound[x + 1] <= right) {
                        hseg[x] += dif;
                    }
                }
            }
            
            int cover = 0;
            for (int k = 0; k < m - 1; ++k) {
                if (hseg[k] > 0) {
                    cover += hbound[k + 1] - hbound[k];
                }
            }
            
            ans = (ans + ll(cover) * (sweep[j + 1].x - sweep[j].x)) % MOD;
            i = j;
        }
        
        return ans;
    }
};

