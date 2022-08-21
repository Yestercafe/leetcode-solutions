class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        vector<int> pos;
        const int N = s.length();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        
        int minute = 0;
        int n = pos.size();
        bool flag = true;
        for (minute = 0; flag; ++minute) {
            flag = false;
            for (int i = 0; i < n; ++i) {
                if (pos[i] != i) {
                    flag = true;
                    if (i - 1 >= 0 && pos[i - 1] == pos[i] - 1) {
                        continue;
                    }
                    if (i + 1 < n && pos[i + 1] == pos[i] + 1) {
                        ++pos[i + 1];
                    }
                    --pos[i];
                }
            }
        }
        
        return minute - 1;
    }
};
