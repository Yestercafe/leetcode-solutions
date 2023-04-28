class Graph {
    static constexpr int maxn = 105;
    struct edge {
      int v, w;
    };

    vector<edge> g[maxn];
    int dis[maxn], vis[maxn];

    void dijkstra(int n, int s) {
      memset(vis, 0, sizeof(vis));
      memset(dis, 63, sizeof(dis));
      dis[s] = 0;
      for (int i = 1; i <= n; i++) {
        int u = 0, mind = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
          if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
        vis[u] = true;
        for (auto ed : g[u]) {
          int v = ed.v, w = ed.w;
          if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
        }
      }
    }
    
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto e : edges) {
            g[e[0] + 1].push_back({e[1] + 1, e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        g[e[0] + 1].push_back({e[1] + 1, e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        dijkstra(n, node1 + 1);
        return dis[node2 + 1] == 0x3f3f3f3f ? -1 : dis[node2 + 1];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

