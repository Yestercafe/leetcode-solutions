class Solution {
    int n;
    vector<vector<pair<int, int>>> ll;
    vector<bool> vis;
    int ans = 987654321;

    void dfs(int idx) {
        vis[idx] = true;
        for (auto& next_p : ll[idx]) {
            ans = min({ans, next_p.second});
            if (vis[next_p.first]) continue;
            dfs(next_p.first);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& r) {
        this->n = n;
        ll.assign(n + 1, {});
        for (auto& t : r) {
            ll[t[0]].push_back(make_pair(t[1], t[2]));
            ll[t[1]].push_back(make_pair(t[0], t[2]));
        }
        vis.assign(n + 1, false);
        
        dfs(1);
        return ans;
    }
};

