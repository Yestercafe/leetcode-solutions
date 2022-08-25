class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [&x](const int& a, const int& b) {
            int da = abs(a - x);
            int db = abs(b - x);
            if (da != db) {
                return da < db;
            } else {
                return a < b;
            }
        });
        vector<int> ret(arr.begin(), arr.begin() + k);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

