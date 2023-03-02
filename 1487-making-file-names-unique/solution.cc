class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_set<string> dup;
        unordered_map<string, int> counter;
        for (auto& name : names) {
            if (counter[name] == 0 && dup.find(name) == dup.cend()) {
                dup.insert(name);
                res.push_back(name);
                ++counter[name];
            } else {
                if (counter[name] == 0) {
                    ++counter[name];
                }
                auto newname = name + "(" + to_string(counter[name]) + ")";
                while (dup.find(newname) != dup.cend()) {
                    newname = name + "(" + to_string(++counter[name]) + ")";
                }
                dup.insert(newname);
                res.push_back(newname);
                ++counter[name];
            }
        }
        return res;
    }
};

