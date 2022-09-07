// 手写 split
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int i = text.find_first_not_of(" "sv), ni;
        int cnt_space = i;
        do {
            ni = text.find_first_of(" "sv, i);
            if (ni != string::npos) {
                words.push_back(text.substr(i, ni - i));
                i = ni;
                ni = text.find_first_not_of(" "sv, i);
                if (ni != string::npos)
                    cnt_space += ni - i;
                else
                    cnt_space += text.length() - i;
            } else {
                words.push_back(text.substr(i));
            }
            i = ni;
        } while (i != string::npos);
        
        if (words.size() < 2) {
            return words.front() + string(cnt_space, ' ');
        }
        
        string quo(cnt_space / (words.size() - 1), ' ');
        string rem(cnt_space % (words.size() - 1), ' ');
        stringstream ss;
        for (int i = 0; i < words.size(); ++i) {
            ss << words[i];
            if (i < words.size() - 1) ss << quo;
            else ss << rem;
        }
        return ss.str();
    }
};

