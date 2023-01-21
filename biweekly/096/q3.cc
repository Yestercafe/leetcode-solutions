class Solution {
public:
    long long maxScore(vector<int>& n1, vector<int>& n2, int k) {
        int n = n1.size();
        vector<pair<int, int>> o2;
        for (int i = 0; i < n; ++i) {
            o2.emplace_back(i, n2[i]);
        }
        sort(o2.begin(), o2.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long s1 = 0;
        for (int i = 0; i < k; ++i) {  // 1 <= k <= n
            pq.push(n1[o2[i].first]);
            s1 += n1[o2[i].first];
        }
        
        long long ans = 0;
        for (int i = k; i <= n; ++i) {
            long long na = (long long) o2[i - 1].second * s1;
            //cout << na << endl;
            ans = max(na, ans);
            if (i == n) break;
            s1 -= pq.top();
            pq.pop();
            s1 += n1[o2[i].first];
            pq.push(n1[o2[i].first]);
        }
        return ans;
    }
};

