class Solution {
    int cal(vector<int>& p) {
        int n = p.size();
        p.insert(p.begin(), 0);
        p.insert(p.begin(), 0);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == 10 || p[i + 1] == 10) {
                ret += 2 * p[i + 2];
            } else {
                ret += p[i + 2];
            }
        }
        return ret;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int a1 = cal(player1);
        int a2 = cal(player2);
        if (a1 > a2) return 1;
        else if (a1 < a2) return 2;
        else return 0;
    }
};

