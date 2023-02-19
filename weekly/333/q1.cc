class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int n = v1.size();
        map<int, int> m;
        
        for (auto& p: v1) {
            m[p[0]] += p[1];
        }
        for (auto& p: v2) {
            m[p[0]] += p[1];
        }
        
        vector<vector<int>> ans;
        for (auto& p: m) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};

