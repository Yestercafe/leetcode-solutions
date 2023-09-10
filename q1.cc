class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // force burst!!
        int n = nums.size();
        vector<int> vis(105);
        for (auto p : nums) {
            for (int i = p[0]; i <= p[1]; ++i) {
                vis[i] = 1;
            }
        }

        return accumulate(vis.begin(), vis.end(), 0);
    }
};
