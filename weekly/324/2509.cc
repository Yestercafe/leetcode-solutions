class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& v : queries) {
            int res = 1;
            int a = v[0], b = v[1];
            while (a != b) {
                if (a > b) {
                    a /= 2;
                } else {
                    b /= 2;
                }
                ++res;
            }
            ans.push_back(res);
        }
        return ans;
    }
};

