class Solution {
public:
    bool isUnique(string astr) {
        bool vis[26] {};
        for (char c : astr) {
            if (vis[c - 'a']) return false;
            vis[c - 'a'] = true;
        }
        return true;
    }
};

