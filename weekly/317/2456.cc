class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, int> cv;
        map<string, vector<int>> ci;
        int n = creators.size();
        int maxx = -1;
        for (int i = 0; i < n; ++i) {
            cv[creators[i]] += views[i];
            ci[creators[i]].push_back(i);
            maxx = max(maxx, cv[creators[i]]);
        }
        
        vector<vector<string>> r;
        for (auto& [c, sv] : cv) {
            if (sv == maxx) {
                r.push_back({c});
            }
        }
        
        for (int i = 0; i < r.size(); ++i) {
            int mv = -1;
            string mn;
            for (auto& j : ci[r[i][0]]) {
                if (mv < views[j]) {
                    mv = views[j];
                    mn = ids[j];
                } else if (mv == views[j] && mn > ids[j]) {
                    mn = ids[j];
                }
            }
            r[i].push_back(mn);
        }
        
        return r;
    }
};

