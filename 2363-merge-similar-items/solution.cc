class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& t1, vector<vector<int>>& t2) {
        vector<vector<int>> ans;
        auto cmp = [](const auto& l, const auto& r) { return l.front() < r.front(); };
        sort(t1.begin(), t1.end(), cmp);
        sort(t2.begin(), t2.end(), cmp);
        int i1 = 0, i2 = 0, n1 = t1.size(), n2 = t2.size();
        while (i1 < n1 && i2 < n2) {
            if (t1[i1][0] == t2[i2][0]) {
                ans.push_back({t1[i1][0], t1[i1][1] + t2[i2][1]});
                ++i1, ++i2;
            } else if (t1[i1][0] < t2[i2][0]) {
                ans.push_back(t1[i1++]);
            } else {
                ans.push_back(t2[i2++]);
            }
        }
        while (i1 != n1) {
            ans.push_back(t1[i1++]);
        }
        while (i2 != n2) {
            ans.push_back(t2[i2++]);
        }
        return ans;
    }
};

