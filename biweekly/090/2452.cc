class Solution {
    int diff(string& a, string& b) {
        int cnt = 0;
        int n = a.length();
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) ++cnt;
        }
        return cnt;
    }
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> r;
        for (auto& a : q) {
            for (auto& b : d) {
                if (diff(a, b) <= 2) {
                    r.push_back(a);
                    break;
                }
            } 
        }
        return r;
    }
};
