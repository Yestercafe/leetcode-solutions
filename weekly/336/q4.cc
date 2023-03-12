class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& lhs, auto& rhs) {
            if (lhs[1] != rhs[1]) {
                return lhs[1] < rhs[1];
            } else {
                return lhs[0] < rhs[0];
            }
        });
        vector<bool> vis(2001);
        for (auto& t : tasks) {
            for (int i = t[0]; i <= t[1]; ++i) {
                if (vis[i]) --t[2];
            }
            for (int i = t[1]; i >= t[0] && t[2] > 0; --i) {
                if (!vis[i]) {
                    vis[i] = true;
                    --t[2];
                }
            }
        }
        return count(vis.begin(), vis.end(), true);
    }
};

