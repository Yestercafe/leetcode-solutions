class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    auto fnd = m.begin();
    for (int i = 0; i < nums.size(); ++i) {
      auto& n = nums[i];
      if ((fnd = m.find(target - n)) != m.end()) {
        return {fnd->second, i};
      }
      m.insert({n, i});
    }
    
    return {-1, -1};
  }
};