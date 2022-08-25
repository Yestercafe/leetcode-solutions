class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto left  = lower_bound(arr.begin(), arr.end(), x);
        auto right = upper_bound(arr.begin(), arr.end(), x);
        
        int r = distance(left, right);
        
        while (r < k) {
            if (left == arr.begin()) {
                ++right;
            } else if (right == arr.end()) {
                --left;
            } else {
                int da = abs(*(left - 1) - x);
                int db = abs(*right - x);
                if (db < da) {
                    ++right;
                } else {
                    --left;
                }
            }
            ++r;
        }
        
        return {left, left + k};
    }
};
