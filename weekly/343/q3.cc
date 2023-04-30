struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

constexpr int dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution {
public:
    int minimumCost(vector<int>& S, vector<int>& T, vector<vector<int>>& sr) {
        pair<int, int> s {0, 0};
        pair<int, int> t {T[0] - S[0], T[1] - S[1]};
        
        map<pair<int, int>, int> idx;
        auto add = [&](int x, int y) {
            auto p = make_pair(x, y);
            if (idx.find(p) != idx.end()) return;
            idx[p] = idx.size();
        };
        add(s.first, s.second);   // s is .0
        add(t.first, t.second);   // t is .1 (except s == t)
        for (auto& v : sr) {
            v[0] -= S[0];
            v[1] -= S[1];
            v[2] -= S[0];
            v[3] -= S[1];
            add(v[0], v[1]);
            add(v[2], v[3]);
        }
        int n = idx.size();
        
        vector g(n, vector<pair<int, int>>{});
        for (int i = 0, N = sr.size(); i < N; ++i) {
            g[idx[s]].push_back({idx[make_pair(sr[i][0], sr[i][1])], sr[i][0] + sr[i][1]});  // initial object
            g[idx[make_pair(sr[i][0], sr[i][1])]].push_back({idx[make_pair(sr[i][2], sr[i][3])], sr[i][4]});  // speical edge
            g[idx[make_pair(sr[i][2], sr[i][3])]].push_back({idx[t], abs(t.first - sr[i][2]) + abs(t.second - sr[i][3])});    // terminal object
        }
        
        std::vector<pair<int, int>> coord(n);
        for (auto& [c, i] : idx) {
            coord[i] = c;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                auto dis = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
                g[i].push_back({j, dis});
                g[j].push_back({i, dis});
            }
        }
        
        vector<int> dis(n, INT_MAX), vis(n);
        priority_queue<node, vector<node>, greater<node>> q;
        
        auto dijkstra = [&](int s) {
            dis[s] = 0;
            q.push({0, s});
            while (!q.empty()) {
                int u = q.top().u;
                q.pop();
                if (vis[u]) continue;
                vis[u] = true;
                for (auto ed : g[u]) {
                    int v = ed.first, w = ed.second;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
        };
        
        dijkstra(idx[s]);     // from initial
        for (auto d : dis) {
            cout << d << ' ';
        }
        cout << endl;
        
        return dis[idx[t]];   // to terminal
    }
};

