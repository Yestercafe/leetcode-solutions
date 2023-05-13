class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans = 0;
        for (auto& s : d) {
            int age = stoi(s.substr(11, 2));
            if (age > 60) {
                ans++;
            }
        }
        return ans;
    }
};

