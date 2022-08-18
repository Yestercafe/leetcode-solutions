class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> requests;
        auto N = groupSizes.size();
        for (int i = 0; i < N; ++i) {
            auto& v = requests[groupSizes[i]];
            v.push_back(i);
            if (groupSizes[i] == v.size()) {
                ret.push_back(move(v));
            }
        }

        return ret;
    }
};

