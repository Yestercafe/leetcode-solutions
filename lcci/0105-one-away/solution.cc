class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.length() < second.length()) {
            first.swap(second);
        }
        int n = first.length(), m = second.length();
        if (n - m > 1) return false;
        bool has_mani = false;
        if (n == m) {
            for (int i = 0; i < n; ++i) {
                if (first[i] != second[i]) {
                    if (has_mani) return false;
                    has_mani = true;
                }
            }
            return true;
        }

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (first[i] != second[j]) {
                if (has_mani) return false;
                has_mani = true;
                ++i;
                continue;
            }
            ++i;
            ++j;
        }
        return true;
    }
};

