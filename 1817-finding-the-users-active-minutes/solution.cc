class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> l;
        for (auto& log : logs) {
            l[log[0]].insert(log[1]);
        }
        for (auto& [_, s] : l) {
            ++ans[s.size() - 1];
        }
        return ans;
    }
};
