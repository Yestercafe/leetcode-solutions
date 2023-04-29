class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa, sb;
        int n = A.size();
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            ans[i + 1] = ans[i];
            sa.insert(A[i]);
            sb.insert(B[i]);
            if (A[i] == B[i]) {
                ++ans[i + 1];
                continue;
            }
            if (sa.find(B[i]) != sa.end()) ++ans[i + 1];
            if (sb.find(A[i]) != sb.end()) ++ans[i + 1];
        }
        ans.erase(ans.begin());
        return ans;
    }
};

