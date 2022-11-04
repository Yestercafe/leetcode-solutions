class Solution {
    using ll = long long;
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> v;
        ll s = 0;
        while (n != 0) {
            v.push_back(n % 10);
            s += n % 10;
            n /= 10;
        }
        
        ll i = 0;
        ll r = 1, a = 0;
        while (s > target) {
            //cout << s << endl;
            s -= v[i];
            a += r * (10 - v[i]);
            r *= 10;
            s += 1;
            if (v.size() <= i + 1) {
                v.push_back(0);
            }
            v[++i]++;
            while (v[i] > 9) {
                //cout << target << endl;
                s -= v[i];
                ++s;
                r *= 10;
                v[i] = 0;
                if (v.size() <= i + 1) {
                    v.push_back(0);
                }
                v[++i]++;
            }
        }
        
        return a;
    }
};

