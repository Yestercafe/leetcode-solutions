class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> cnts;
        for (auto& c : s1) ++cnts[c];
        for (auto& c : s2) {
            unordered_map<char, int>::iterator itr;
            if ((itr = cnts.find(c)) == cnts.end()) {
                return false;
            }
            --itr->second;
            if (itr->second == 0) {
                cnts.erase(itr);
            }
        }
        
        if (cnts.size() != 0)
            return false;
        return true;
    }
};

