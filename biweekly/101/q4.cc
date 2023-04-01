class Solution {
    struct edge {
      int v, w;
    };

    struct node {
      int dis, u;

      bool operator>(const node& a) const { return dis > a.dis; }
    };

    vector<vector<edge>> e;
    vector<int> dis, vis;
    priority_queue<node, vector<node>, greater<node>> q;

    void dijkstra(int n, int s, int ra, int rb) {
      dis[s] = 0;
      q.push({0, s});
      while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
          int v = ed.v, w = ed.w;
          if ((u == ra && v == rb) || (u == rb && v == ra)) continue;
          if (dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            q.push({dis[v], v});
          }
        }
      }
    }
    
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        constexpr int inf = 0x3f3f3f3f;
        e = vector(n, vector<edge>{});
        dis = vector(n, 0);
        vis = vector(n, 0);
        for (auto& ed : edges) {
            e[ed[0]].push_back({ed[1], 1});
            e[ed[1]].push_back({ed[0], 1});
        }
        
        int ans = INT_MAX;
        for (int u = 0; u < n; ++u) {
            for (auto [v, _] : e[u]) {
                for (auto& a : dis) a = inf;
                for (auto& a : vis) a = 0;
                while (!q.empty()) q.pop();
                
                dijkstra(n, u, u, v);
                
                ans = min(dis[v] + 1, ans);
            }
        }
        return ans == inf + 1 ? -1 : ans;
    }
};

