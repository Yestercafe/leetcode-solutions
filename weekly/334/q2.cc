class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> ans;
        long long s = 0;
        for (auto ch : word) {
            s = (s * 10) % m;
            s = (s + ch - '0') % m;
            ans.push_back(s % m == 0);
        }
        return ans;
    }
};

