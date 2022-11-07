class Solution {
    struct S {
        int cost;
        int idx;
        bool isLeft;
        
        friend bool operator<(const S& lhs, const S& rhs) {
            if (lhs.cost != rhs.cost) {
                return lhs.cost > rhs.cost;
            } else {
                return lhs.idx > rhs.idx;
            }
        }
    };
    
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<S> pq;
        int n = costs.size();
        long long res = 0;
        int sel_cnt = 0;
        int left = -1, right = -1;
        if (n < 2 * candidates) {
            for (int i = 0; i < n; ++i) {
                pq.push({costs[i], i, false});
            }
        } else {
            for (int i = 0; i < candidates; ++i) {
                pq.push({costs[i], i, true});
                pq.push({costs[n - 1 - i], n - 1 - i, false});
            }
            left = candidates, right = n - 1 - candidates;
        }
        
        while (sel_cnt < k) {
            if (n - sel_cnt <= 2 * candidates) {
                res += pq.top().cost;
                pq.pop();
            } else {
                auto [cost, idx, isLeft] = pq.top();
                //cout << "cost = " << cost << ", idx = " << idx << endl;
                pq.pop();
                res += cost;
                if (isLeft) {
                    //cout << "left: " << left << endl;
                    pq.push({costs[left], left, true});
                    ++left;
                } else {
                    //cout << "right: " << right << endl;
                    pq.push({costs[right], right, false});
                    --right;
                }
            }
            ++sel_cnt;
        }
        
        return res;
    }
};

