class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> m(nums.begin(), nums.end());
        return count_if(m.begin(), m.end(), [&](int x) { return (m.find(x - diff) != m.end()) && (m.find(x + diff) != m.end()); });
    }
};

