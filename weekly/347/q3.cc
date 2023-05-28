class Solution {
    using i64 = long long;
public:
    long long minimumCost(string s) {
        int n = s.length();
        s.insert(s.begin(), 1 - (s[0] - '0') + '0');
        vector<int> v;
        i64 lsum = 0, rsum = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != s[i - 1]) {
                v.push_back(i - 1);
                rsum += 1LL * (i - 1);
            }
        }
        v.push_back(n);
        rsum -= 1LL * v[0];
        rsum += 1LL * n;
        
        
        i64 ans = INT64_MAX;
        int m = v.size();
        for (int i = 0; i < m - 1; ++i) {
            i64 sum = 0;
            lsum += v[i];
            
            int r_cnt = m - i - 1;
            sum += lsum + 1LL * r_cnt * n - rsum;
            
            ans = min(sum, ans);
            rsum -= v[i + 1];
        }
        
        return ans;
    }
};

