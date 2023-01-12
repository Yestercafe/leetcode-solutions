class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& v : knowledge) {
            dict[v[0]] = v[1];
        }

        vector<pair<string, bool>> v;
        string ans;
        vector<char> vc;
        for (auto&& c : s) {
            switch (c) {
              case '(':
                if (vc.size() == 0) break;
                v.emplace_back(string(vc.cbegin(), vc.cend()), false);
                vc.clear();
                break;
              case ')':
                v.emplace_back(string(vc.cbegin(), vc.cend()), true);
                vc.clear();
                break;
              default:
                vc.push_back(c);
                break;
            }
        }
        if (!vc.empty()) {
            v.emplace_back(string(vc.cbegin(), vc.cend()), false);
        }

        for (auto& p : v) {
            if (p.second) {
                auto fnd = dict.find(p.first);
                if (fnd != dict.cend()) {
                    p.first = fnd->second;
                } else {
                    p.first = "?";
                }
            }
        }

        stringstream ss;
        for (auto& [f, _] : v) {
            ss << f;
        }

        return ss.str();
    }
};

