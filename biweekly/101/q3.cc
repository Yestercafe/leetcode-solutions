class Solution {
    using i64 = long long;
public:
    i64 makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        i64 ans = 0;
        int block = n / g;
        
        for (int f = 0; f < g; ++f) {
            vector<pair<int, int>> v;   // (v, i)
            v.reserve(block);
            for (int i = f; i < n; i += g) {
                v.push_back({arr[i], i});
            }
            sort(v.begin(), v.end());
            vector<i64> pref(block + 1);
            for (int i = 0; i < block; ++i) {
                pref[i + 1] = pref[i] + v[i].first;
            }
            
            i64 mm = INT64_MAX;
            for (int i = 0; i < block; ++i) {
                int c = arr[v[i].second];
                mm = min(mm, (1LL * c * i - pref[i]) + (pref[block] - pref[i] - 1LL * c * (block - i)));
                // cout << mm << endl;
            }
            ans += mm;
        }
        
        return ans;
    }
};

