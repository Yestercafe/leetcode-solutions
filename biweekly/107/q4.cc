// 没用上
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& ls, int x, vector<int>& qs) {
        int nq = qs.size();
        vector<pair<int, int>> qis(nq);
        for (int i = 0; i < nq; ++i) {
            qis[i].first = qs[i];
            qis[i].second = i;
        }
        sort(qis.begin(), qis.end());
        sort(ls.begin(), ls.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        vector ans(nq, 0);
        
        int nl = ls.size();
        int l = 0, r = 0;   // [0, l] [x, r)
        // Fenwick<int> fen(n + 1);
        map<int, int> cnt;
        for (int iq = 0; iq < nq; ++iq) {
            // cout << iq << ' ' << qis[iq].first << ' ' << qis[iq].second << endl;
            // cout << r << ls[r][1] << ' ' << qis[iq].first << endl;
            while (r < nl && ls[r][1] <= qis[iq].first) {
                ++cnt[ls[r][0]];
                // cout << "add: " << ls[r][0] << endl;
                ++r;
            }
            while (l < r && l < nl && ls[l][1] < qis[iq].first - x) {
                auto fnd = cnt.find(ls[l][0]);
                // cout << "del: " << ls[l][0] << ' ' << fnd->second << endl;
                --fnd->second;
                if (fnd->second == 0) cnt.erase(fnd);
                ++l;
            }
            ans[qis[iq].second] = n - cnt.size();
        }
        
        return ans;
    }
};

