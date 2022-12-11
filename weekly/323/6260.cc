constexpr int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

class Solution {
    struct D {
        int val;
        int x, y;
        bool operator<(const D& rhs) const {
            return this->val > rhs.val;
        }
        D(int val, int x, int y) : val{val}, x{x}, y{y} {}
    };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();

        vector<pair<int, int>> sorted_q;
        transform(queries.begin(), queries.end(), back_inserter(sorted_q), [i = 0](const int& a) mutable -> pair<int, int> { return {i++, a}; });
        sort(sorted_q.begin(), sorted_q.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; });

        vector<int> ans(k);
        priority_queue<D> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = 0;
        int cnt = 0;

        for (auto& [qi, q] : sorted_q) {
            while (!pq.empty() && pq.top().val < q) {
                ++cnt;
                auto [v, i, j] = pq.top();
                pq.pop();
                for (auto d : dir) {
                    auto x = i + d[0];
                    auto y = j + d[1];
                    if (0 <= x && x < n && 0 <= y && y < m && grid[x][y]) {
                        pq.push({grid[x][y], x, y});
                        grid[x][y] = 0;
                    }
                }
            }
            ans[qi] = cnt;
        }

        return ans;
    }
};

