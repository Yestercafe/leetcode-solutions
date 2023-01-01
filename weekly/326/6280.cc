class Solution {
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        int qq = 0, ww = 0;
        int q = 0, w = 1000000;
        for (int a = left; a <= right; ++a) {
            if (isPrime(a)) {
                //cout << "p:" << a << endl;
                if (qq == 0) { qq = a; continue; }
                else if (ww == 0) {
                    ww = a;
                    q = qq;
                    w = ww;
                }
                else {
                    qq = ww;
                    ww = a;
                    // cout << qq << " " << ww << endl;
                    if (ww - qq < w - q) {
                        w = ww;
                        q = qq;
                    }
                }
            }
        }
        if (q == 0 || w == 1000000) return {-1, -1};
        return {q, w};
    }
};

