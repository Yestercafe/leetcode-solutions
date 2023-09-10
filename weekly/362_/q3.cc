class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int N = 3;

        vector<pair<int, int>> zeros;
        vector<pair<int, int>> redun; 

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    zeros.push_back({i, j});
                } else if (grid[i][j] > 1) {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        redun.push_back({i, j});
                    }
                }
            }
        }

        int n = zeros.size();
        if (n == 0) return 0;
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        
        int minn = INT_MAX;

        auto distance = [](pair<int, int>& lhs, pair<int, int>& rhs) {
            return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
        };

        do {
            int dis = 0;
            for (int i = 0; i < n; ++i) {
                dis += distance(zeros[i], redun[perm[i] - 1]);
            }
            minn = min(minn, dis);
        } while (next_permutation(perm.begin(), perm.end()));

        return minn;
    }
};
