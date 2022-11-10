class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, -1), s, t;
        for (int i = 0; i < n; ++i) {
            int k = nums[i];
            while (!t.empty() && nums[t.back()] < k) {
                r[t.back()] = k;
                t.pop_back();
            }
            
            int j = (int) s.size() - 1;
            while (j >= 0 && nums[s[j]] < k) {
                --j;
            }
            
            t.insert(t.end(), s.begin() + (j + 1), s.end());
            s.resize(j + 1);
            s.push_back(i);
        }
        return r;
    }
};
