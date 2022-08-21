class Solution {
public:
    string largestPalindromic(string num) {
        // 不能含前导零意思是不能以 0 结尾
        vector<int> counter(10, 0);
        for (int i = 0; i < num.length(); ++i) {
            ++counter[num[i] - '0'];
        }
        char rem = 0;
        stringstream ss;
        for (int i = 9; i >= 1; --i) {
            // cout << counter[i] << endl;
            if (rem == 0 && counter[i] % 2 == 1) rem = i + '0';
            if (counter[i] / 2 == 0) continue;
            ss << string(counter[i] / 2, i + '0');
        }
        
        if (ss.str().empty()) {
            if (rem != 0)
                return string(1, rem);
            else {    // must be 0
                return "0"s;
            }
        } else {    // specify 0
            if (counter[0] / 2 > 0) {
                ss << string(counter[0] / 2, '0');
            }
            if (rem == 0 && counter[0] % 2 == 1) {
                rem = '0';
            }
        }
        
        string rev = ss.str();
        reverse(rev.begin(), rev.end());
        ss << rem << rev;
        return ss.str();
    }
};
