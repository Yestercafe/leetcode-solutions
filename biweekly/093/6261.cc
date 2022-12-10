class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxx = -1;
        for (auto& s : strs) {
            bool isN = true;
            for (auto& c : s) {
                if (isalpha(c)) {
                    isN = false;
                    break;
                }
            }
            if (isN) {
                maxx = max(maxx, stoi(s));
            } else {
                maxx = max(maxx, (int) s.length());
            }
        }
        return maxx;
    }
};

