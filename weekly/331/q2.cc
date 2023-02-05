class Solution {
    string vowels = "aeiou";
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& qs) {
        int n = words.size();
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1];
            pref[i] += (vowels.find(words[i - 1].front()) != string::npos && vowels.find(words[i - 1].back()) != string::npos);
        }
        
        int nq = qs.size();
        vector<int> ans;
        ans.reserve(nq);
        for (auto& q : qs) {
            int l = q.front(), r = q.back();
            ans.push_back(pref[r + 1] - pref[l]);
        }
        return ans;
    }
};

