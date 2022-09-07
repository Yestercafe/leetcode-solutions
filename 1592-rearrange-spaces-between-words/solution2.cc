// stringstream
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        stringstream input;
        input << text;
        int cnt_space = text.length();
        string word;
        while (input >> word) {
            words.push_back(word);
            cnt_space -= word.length();
        }
        
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
