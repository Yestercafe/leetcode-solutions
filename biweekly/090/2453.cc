class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, vector<int>> m;
        int x = 0, p = 0;
        vector<int> vs;
        for (auto& a : nums) {
            auto& k = m[a % space];
            k.push_back(a);
            if (k.size() > x) {
                x = k.size();
                vs.clear();
                vs.push_back(a % space);
            } else if (k.size() == x) {
                vs.push_back(a % space);
            }
        }
        
        int mm = *min_element(m[vs[0]].begin(), m[vs[0]].end());
        for (auto& v : vs) {
            mm = min(*min_element(m[v].begin(), m[v].end()), mm);
        }
        return mm;
    }
};
