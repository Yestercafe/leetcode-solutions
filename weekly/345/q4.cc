class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector g(n, vector<int>{});
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            std::vector<int> seq {i};
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                auto fr = q.front();
                q.pop();
                for (auto nxt : g[fr]) {
                    if (vis[nxt]) continue;
                    vis[nxt] = true;
                    q.push(nxt);
                    seq.push_back(nxt);
                }
            }
            
            int ns = seq.size();
            bool flag = true;
            for (auto i : seq) {
                if (g[i].size() != ns - 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
        
        return ans;
    }
};

