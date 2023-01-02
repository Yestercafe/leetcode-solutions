class Solution {
    using pii = pair<int, int>;
    static constexpr int MOD = 1e9 + 7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pii, vector<pii>, less<pii>> buys;
        priority_queue<pii, vector<pii>, greater<pii>> sells;
        for (const auto& o : orders) {
            auto price = o[0], amount = o[1], ot = o[2];
            switch (ot) {
                case 0: {   // 0 is buying
                    while (amount > 0 && !sells.empty() && sells.top().first <= price) {
                        pii p = sells.top();
                        sells.pop();
                        if (p.second <= amount) {
                            amount -= p.second;
                        } else {
                            p.second -= amount;
                            amount = 0;
                            sells.push(p);
                        }
                    }
                    if (amount > 0) {
                        buys.emplace(price, amount);
                    }
                }
                break;
                case 1: {   // 1 is selling
                    while (amount > 0 && !buys.empty() && buys.top().first >= price) {
                        pii p = buys.top();
                        buys.pop();
                        if (p.second <= amount) {
                            amount -= p.second;
                        } else {
                            p.second -= amount;
                            amount = 0;
                            buys.push(p);
                        }
                    }
                    if (amount > 0) {
                        sells.emplace(price, amount);
                    }
                }
                break;
            }
        }
        
        int ans = 0;
        while (!buys.empty()) {
            const auto& [_, a] = buys.top();
            ans = (ans + a) % MOD;
            buys.pop();
        }
        while (!sells.empty()) {
            const auto& [_, a] = sells.top();
            ans = (ans + a) % MOD;
            sells.pop();
        }
        
        return ans % MOD;
    }
};

