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
        sort(v.begin(), v.end());
        string *pname = nullptr;
        bool added = false;
        vector<string> ans;
        for (int i = 0; i < n - 2; ++i) {
            if (!pname) { pname = &v[i].first; }
            if (*pname == v[i].first && added) continue;
            added = false;
            if (v[i + 2].first == v[i].first) {
                pname = &v[i].first;
                if (!added && v[i + 2].second - v[i].second <= 60) {
                    // cout << v[i].first << ": " << v[i].second.first << ':' << v[i].second.second << endl;
                    ans.push_back(*pname);
                    added = true;
                }
            } else {
                ++i;
            }
        }
        return ans;
    }
};

