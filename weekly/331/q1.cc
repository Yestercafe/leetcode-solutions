class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long ans = accumulate(gifts.begin(), gifts.end(), 0ll);
        for (int i = 0; i < k; ++i) {
            int sqr = int(floor(sqrt(pq.top())));
            int minus = pq.top() - sqr;
            ans -= minus;
            pq.pop();
            pq.push(sqr);
        }
        return ans;
    }
};

