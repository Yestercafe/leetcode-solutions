class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        set<int> s;
        int i = 0;
        int f = 1;
        while (true) {
            if (s.count(i)) break;
            s.insert(i);
            i = (i + f * k) % n;
            ++f;
        }
        for (int i = 0; i < n; ++i) {
            if (s.count(i)) continue;
            ans.push_back(i + 1);
        }
        return ans;
    }
};

