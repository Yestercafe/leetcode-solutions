class Solution {
public:
    int maximizeWin(vector<int>& pps, int k) {
        if (pps.back() - pps.front() < 2 * (k + 1)) {
            return pps.size();
        }
        map<int, int> m;
        for (auto i : pps) ++m[i];
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        vector<pair<int, int>> v(m.begin(), m.end());
        
        int sum = 0;
        int i {};
        for (i = 0; i < v.size() && v[i].first - v[0].first <= k; ++i) {
            sum += v[i].second;
        }
        //cout << sum << endl;
        q.push({sum, v[0].first});
        int ans = 0;
        int j {};
        for (j = i, i = 0; i < v.size() && j < v.size(); ++j) {
            sum += v[j].second;
            while (i <= j && v[j].first - v[i].first > k) {
                sum -= v[i].second;
                //cout << "after - " << sum << endl;
                ++i;
                while (!q.empty() && q.front().second + k < v[i].first) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }
            //cout << sum << endl;
            if (!pq.empty()) ans = max(ans, sum + pq.top());
            q.push({sum, v[i].first});
        }
        //cout << endl;
        
        return ans;
    }
};

