class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for (auto& a : nums) ++m[a];
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        });
        
        vector<int> r;
        for (auto& [n, times] : v) {
            for (int i = 0; i < times; ++i) {
                r.push_back(n);
            }
        }
        return r;
    }
};

