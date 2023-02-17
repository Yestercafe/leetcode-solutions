class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector pref(n + 1, 0);
        vector<int> st;
        st.push_back(0);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (pref[i] < pref[st.back()]) st.push_back(i);
        }
        int ans = 0;
        for (int i = n; i > 0; --i) {
            while (!st.empty() && pref[i] > pref[st.back()]) {
                ans = max(ans, i - st.back());
                st.pop_back();
            }
        }
        return ans;
    }
};

