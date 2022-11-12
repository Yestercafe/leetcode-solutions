class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> s;
        while (!nums.empty()) {
            auto m = *min_element(nums.begin(), nums.end());
            auto M = *max_element(nums.begin(), nums.end());
            
            s.insert((double)(m + M) / 2.);
            nums.erase(find(nums.begin(), nums.end(), m));
            nums.erase(find(nums.begin(), nums.end(), M));
        }
        return s.size();
    }
};
