class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        vector<int> o(n);
        for (int i = 1; i < n; ++i) {
            o[i] = o[i - 1] ^ d[i - 1];
        }
        if ((o[0] ^ o[n - 1]) != d[n - 1]) {
            return false;
        } else {
            return true;
        }

    }
};

