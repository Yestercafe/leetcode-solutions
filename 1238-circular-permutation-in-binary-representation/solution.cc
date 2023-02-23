class Solution {
    int s;
    vector<int> ans;
    void notp(int p) {
        if (p == 0) {
            s ^= 1;
            ans.push_back(s);
            return ;
        }
        notp(p - 1);
        s ^= (1 << p);
        ans.push_back(s);
        notp(p - 1);
    }
public:
    vector<int> circularPermutation(int n, int start) {
        ans.push_back(start);
        s = start;
        notp(n - 1);
        return ans;
    }
};

