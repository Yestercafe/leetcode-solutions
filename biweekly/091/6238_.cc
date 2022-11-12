class Solution {
    constexpr static int MOD = 1e9 + 7;
public:
    int countGoodStrings(int l, int h, int z, int o) {
        vector<int> f(100005, 0);
        f[z] += 1;
        f[o] += 1;
        deque<pair<int, int>> v;
        v.push_back({z, 1});
        v.push_back({o, 1});
        while (!v.empty()) {
            int size = v.size();
            map<int, int> inc;
            while (size--) {
                auto [front, amount] = v.front();
                
                if (front + z <= h) {
                    f[front + z] = (f[front + z] + amount) % MOD;
                    inc[front + z] = (inc[front + z] + amount) % MOD;
                }
                if (front + o <= h) {
                    f[front + o] = (f[front + o] + amount) % MOD;
                    inc[front + o] = (inc[front + o] + amount) % MOD;
                }
                
                v.pop_front();
            }
            
            for (auto& p : inc) {
                v.push_back(p);
            }
        }
        
        int sum = 0;
        for (int i = l; i <= h; ++i) {
            sum = (sum + f[i]) % MOD;
        }
        return sum;
    }
};

