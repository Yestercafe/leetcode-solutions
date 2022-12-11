class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();
        
        int s = 0;
        for (int ci = 0; ci < cn; ++ci) {
            int a = 0;
            for (int ri = 0; ri < rn; ++ri) {
                auto me = max_element(grid[ri].begin(), grid[ri].end());
                a = max(a, *me);
                grid[ri].erase(me);
            }
            s += a;
        }
        return s;
    }
};

