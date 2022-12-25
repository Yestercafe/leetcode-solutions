class Solution {
public:
    int captureForts(vector<int>& forts) {
        int state = 0;
        int cnt, ans;
        cnt = ans = 0;
        int n = forts.size();
        for (int i = 0; i < n; ++i) {
            if (forts[i] != 0) {
                if (state == 0) {
                    state = forts[i];
                    cnt = 0;
                } else if (state == -forts[i]) {
                    ans = max(ans, cnt);
                    cnt = 0;
                    state = -state;
                } else {
                    cnt = 0;
                }
            } else {
                cnt++;
            }
        }
        return ans;
    }
};

