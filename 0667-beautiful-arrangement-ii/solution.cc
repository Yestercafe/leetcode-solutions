class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v;
        deque<int> g(n, 0);
        iota(g.begin(), g.end(), 1);
        for (int i = 0; i < k; ++i) {
            if (i < k) {
                v.push_back(g.front());
                g.pop_front();
            }
            ++i;
            if (i < k) {
                v.push_back(g.back());
                g.pop_back();
            }
        }
        if (k % 2 == 1) {
            for (auto itr = g.begin(); itr != g.end(); ++itr) {
                v.push_back(*itr);
            }
        } else {
            for (auto itr = g.rbegin(); itr != g.rend(); ++itr) {
                v.push_back(*itr);
            }
        }
        
        return v;
    }
};

