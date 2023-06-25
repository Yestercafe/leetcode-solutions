class Solution {
    struct S {
        int i;
        int p;
        int h;
        char d;
    };
public:
    vector<int> survivedRobotsHealths(vector<int>& ps, vector<int>& hs, string ds) {
        int np = ps.size();
        vector pans(np, -1);
        vector<S> s(np);
        for (int i = 0; i < np; ++i) {
            s[i].i = i;
            s[i].p = ps[i];
            s[i].h = hs[i];
            s[i].d = ds[i];
        }
        
        sort(s.begin(), s.end(), [](const S& a, const S& b) {
            return a.p < b.p;
        });
        
        deque<pair<int, int>> hr;    // idx, hr
        for (int i = 0; i < np; ++i) {
            if (s[i].d == 'R') {
                hr.push_back({s[i].i, s[i].h});
            } else {    // == 'L'
                while (!hr.empty() && s[i].h > 0 && hr.back().second < s[i].h) {
                    hr.pop_back();
                    s[i].h--;
                }
                if (!hr.empty()) {
                    if (hr.back().second == s[i].h) {
                        hr.pop_back();
                    } else if (hr.back().second > s[i].h) {
                        hr.back().second--;
                    }
                } else {
                    pans[s[i].i] = s[i].h;
                }
            }
        }
        for (auto [idx, h] : hr) {
            pans[idx] = h;
        }
        
        vector<int> ans;
        ans.reserve(np);
        for (auto a : pans) {
            if (a > 0) ans.push_back(a);
        }
        return ans;
    }
};

