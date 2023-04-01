class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> vs;
        for (int i = 0; i < 26; ++i) {
            vs['a' + i] = i + 1;
        }
        int m = chars.size();
        for (int i = 0; i < m; ++i) {
            vs[chars[i]] = vals[i];
        }
        
        int n = s.size();
        vector<int> ss(n);
        for (int i = 0; i < n; ++i) {
            ss[i] = vs[s[i]];
            // cout << ss[i] << ' ';
        }
        // cout << endl;
        
        int maxsum = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + ss[i] > 0) {
                sum += ss[i];
                maxsum = max(maxsum, sum);
            } else {
                sum = 0;
            }
        }
        return maxsum;
    }
};

