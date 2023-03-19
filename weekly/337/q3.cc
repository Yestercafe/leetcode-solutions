class Solution {
    int dis[1001];
    int n;
    int ans = 0;
    vector<int> v;
    int k;
    void dfs(int i) {
        if (i == n) {
            ++ans;
            return ;
        }
        if (!dis[v[i]]) {
            int mem[2];
            if (v[i] + k <= 1000) {
                mem[0] = dis[v[i] + k];
                dis[v[i] + k] = true;
            }
            if (v[i] - k >= 1) {
                mem[1] = dis[v[i] - k];
                dis[v[i] - k] = true;
            }
            dfs(i + 1);
            if (v[i] + k <= 1000) dis[v[i] + k] = mem[0];
            if (v[i] - k >= 1) dis[v[i] - k] = mem[1];
        }
        
        dfs(i + 1);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        v = nums;
        this->k = k;
        dfs(0);
        return ans - 1;
    }
};

