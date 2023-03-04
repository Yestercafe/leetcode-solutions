class Solution {
    vector<vector<int>> gr;
    vector<unordered_set<int>> g;
    vector<int> distance;
    vector<int> anss;
    void bfs_d(int s) {
        deque<int> q;
        q.push_back(0);
        int depth = 0;
        vector<bool> vis(gr.size());
        vis[0] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int top = q.front();
                q.pop_front();
                distance[top] = depth;
                for (auto nxt : gr[top]) {
                    if (vis[nxt]) continue;
                    vis[nxt] = true;
                    q.push_back(nxt);
                }
            }
            ++depth;
        }
    }
    int k;
    int ans;
    void bfs(int s) {
        deque<int> q;
        q.push_back(0);
        int depth = 0;
        vector<bool> vis(gr.size());
        vis[0] = true;
        while (!q.empty()) {
            int top = q.front();
            q.pop_front();
            int prev_kk = anss[top];
            for (auto nxt : gr[top]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push_back(nxt);
                anss[nxt] = prev_kk + (g[nxt].find(top) != g[nxt].end() ? 1 : 0) - (g[top].find(nxt) != g[top].end() ? 1 : 0);
                if (anss[nxt] >= k) ++ans;
            }
        }
    }

public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        gr = vector<vector<int>>(n);
        g = vector<unordered_set<int>>(n);
        anss = vector<int>(n);
        
        for (auto& e : edges) {
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        for (auto& guess : guesses) {
            g[guess[0]].insert(guess[1]);
        }
        
        distance = vector<int>(n);
        bfs_d(0);
        
        int kk = 0;
        for (auto& guess : guesses) {
            if (distance[guess[0]] < distance[guess[1]]) ++kk;
        }
        ans = 0;
        if (kk >= k) ++ans;
        anss[0] = kk;
        this->k = k;
        bfs(0);
        return ans;
    }
};

