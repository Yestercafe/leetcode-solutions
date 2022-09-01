class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> sum; sum.reserve(n);
        for (int i = 0; i < n; ++i) {
            int discount = 0;
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            sum.push_back(prices[i] - discount);
        }
        return sum;
    }
};

