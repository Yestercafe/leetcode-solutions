class Solution {
    vector<bool> vis, bob_vis;
    int n;
    int bob;
    vector<int> bob_path;
    vector<vector<int>> e;
    int cur_score, max_score = -1e9 - 7;
    vector<int> amount;
    
    bool find_bob(int p) {
        if (p == bob) {
            bob_path.push_back(p);
            return true;
        }
        for (auto& n : e[p]) {
            if (vis[n]) continue;
            vis[n] = true;
            if (find_bob(n)) {
                bob_path.push_back(p);
                return true;
            }
        }
        return false;
    }
    
    void dfs(int p, int depth) {
        if (!bob_vis[p]) {
            if (depth < bob_path.size() && bob_path[depth] == p) {
                cur_score += amount[p] / 2;
            }
            else {
                cur_score += amount[p];
            }
        }
        cout << p << " " << cur_score << endl;
            
        if (depth < bob_path.size())
            bob_vis[bob_path[depth]] = true;
        bool isLeaf = true;
        for (auto& next : e[p]) {
            //cout << next << endl;
            if (vis[next]) continue;
            isLeaf = false;
            vis[next] = true;
            dfs(next, depth + 1);
        }
        if (depth < bob_path.size())
            bob_vis[bob_path[depth]] = false;
        if (isLeaf)
            max_score = max(max_score, cur_score);
        
        if (!bob_vis[p]) {
            if (depth < bob_path.size() && bob_path[depth] == p) {
                cur_score -= amount[p] / 2;
            }
            else {
                cur_score -= amount[p];
            }
        }
    }
    
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        this->bob = bob;
        n = amount.size();
        e.assign(n, {});
        this->amount = amount;

        for (auto& p : edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }

        vis.assign(n, false);
        vis[0] = true;
        find_bob(0);
        //bob_path.push_back(0);
        for (auto a : vis) a = false;
        bob_vis.assign(n, false);
        
        vis[0] = true;
        bob_vis[bob] = true;
        dfs(0, 0);
        
        return max_score;
    }
};
