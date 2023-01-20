class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            ans += top;
            //cout << top << endl;
            pq.pop();
            top = ceil(top / 3.);
            pq.push(top);
        }
        return ans;
    }
};
