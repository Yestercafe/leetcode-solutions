class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto& l : logs) {
            if (l[0] == '.' && l[1] == '.') {
                if (depth > 0) --depth;
            } else if (l[0] == '.' && l[1] == '/') {
                continue;
            } else {
                ++depth;
            }
        }
        return depth;
    }
};

