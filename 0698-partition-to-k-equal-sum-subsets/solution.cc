class Solution {
    vector<bool> vis;
    int total, cap, k;
    int n;
    vector<int> nums;
    
    bool dfs(int idx, int sum, int cnt) {
        if (cnt == k) return true;
        if (sum == cap) return dfs(0, 0, cnt + 1);
        
        for (int i = idx; i < n; ++i) {
            if (vis[i] || sum + nums[i] > cap) continue;
            
            vis[i] = true;
            if (dfs(idx + 1, sum + nums[i], cnt))
                return true;
            vis[i] = false;
            
            if (sum == 0) return false;   // necessary
        }
       
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->n = nums.size();
        this->total = accumulate(nums.begin(), nums.end(), 0);
        this->k = k;
        this->nums = nums;
        if (total % k != 0) return false;  // 不能分割
        cap = total / k;
        sort(nums.begin(), nums.end(), greater<int>());
        vis.assign(n, false);
        return dfs(0, 0, 0);
    }
};

