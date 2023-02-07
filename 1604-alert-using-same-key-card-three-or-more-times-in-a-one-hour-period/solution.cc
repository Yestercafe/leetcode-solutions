int operator-(pair<int, int> lhs, pair<int, int> rhs) {
    return 60 * (lhs.first - rhs.first) + (lhs.second - rhs.second);
}

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        vector<pair<string, pair<int, int>>> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.push_back({keyName[i], make_pair(stoi(keyTime[i].substr(0, 2)), stoi(keyTime[i].substr(3, 2)))});
        }
        sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });
        map<string, vector<pair<int, int>>> timer;
        for (auto& [name, t] : v) {
            timer[name].push_back(t);
        }
        vector<string> ans;
        for (auto& [name, ts] : timer) {
            for (int i = 0; i < ts.size() - 2; ++i) {
                if (ts[i + 2] - ts[i] <= 60) {
                    ans.push_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};

