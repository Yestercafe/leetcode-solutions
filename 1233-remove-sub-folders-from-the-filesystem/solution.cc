class Solution {
    bool is_starts_with(string& str, string& pref) {
        int n = pref.length();
        int i;
        for (i = 0; i < n; ++i)
            if (str[i] != pref[i]) return false;
        if (str[i] == '/') return true;
        return false;
    }
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(), f.end());
        vector<string> ans;
        ans.push_back(f.front());
        int n = f.size();
        for (int i = 1; i < n; ++i) {
            int psize = ans.back().size();
            if (psize >= f[i].size() || !is_starts_with(f[i], ans.back())) ans.push_back(f[i]);
        }
        return ans;
    }
};

