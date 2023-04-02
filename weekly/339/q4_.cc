class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n);
        for (int b : banned) {
            ans[b] = -1;
        }
        int mid = k / 2;
        ans[p] = -1;
        
        queue<int> q;
        q.push(p);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int top = q.front();
                q.pop();
                
                int leftest = max(0, top - k + 1);
                int rightest = min(n - 1, top + k - 1);
                for (int i = leftest; i + k - 1 <= rightest; ++i) {
                    int l = i, r = i + k - 1;
                    if (k % 2) {
                        if (top == i + mid) {
                            continue;
                        }
                    }
                    int next = (k - 1) - (top - i) + i;
                    if (ans[next] != 0) continue;
                    ans[next] = depth;
                    q.push(next);
                }
            }
            ++depth;
        }
        for (auto& a : ans) {
            if (a == 0) a = -1;
        }
        ans[p] = 0;
        
        return ans;
    }
};

