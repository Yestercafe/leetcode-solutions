struct Trie {
    map<int, Trie*> nxt;
    int cnt; 
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        auto t = new Trie{};
        for (int i = 0; i < n; ++i) {
            auto curr = t;
            for (int j = 0; j < n; ++j) {
                if (!curr->nxt.count(grid[i][j])) {
                    curr->nxt[grid[i][j]] = new Trie{};
                }
                curr = curr->nxt[grid[i][j]];
            }
            ++curr->cnt;
        }
        for (int j = 0; j < n; ++j) {
            auto curr = t;
            for (int i = 0; i < n; ++i) {
                if (!curr->nxt.count(grid[i][j])) {
                    break;
                }
                curr = curr->nxt[grid[i][j]];
            }
            ans += curr->cnt;
        }

        return ans;
    }
};

