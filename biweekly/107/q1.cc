class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> s;
        int ans = 0;
        for (auto w : words) {
            if (s.count(w)) {
                ans++;
            }
            reverse(w.begin(), w.end());
            s.insert(w);
        }
        return ans;
    }
};

