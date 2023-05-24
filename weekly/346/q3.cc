class Solution {
    int dfs(string& s, int a, int i, int sum) {
        int n = s.length();
        if (n == i) {
            if (a == sum) return true;
            return false;
        }
        int st = i;
        bool ret = false;
        for (; i < n; ++i) {
            int new_sum = sum + stoi(s.substr(st, i - st + 1));
            if (new_sum > a) break;
            ret |= dfs(s, a, i + 1, new_sum);
        }
        return ret;
    }
    int sum(int n, int a) {
        string s = to_string(n);
        return dfs(s, a, 0, 0);
    }
public:
    int punishmentNumber(int n) {
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            if (sum(i * i, i)) {
                p += i * i;
            }
        }
        return p;
    }
};

