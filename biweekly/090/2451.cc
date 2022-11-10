class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.front().size();
        vector<string> ww;
        for (auto w : words) {
            int offset = w[0] - 'a';
            for (auto& c : w) c -= offset;
            ww.push_back(w);
        }
        
        int N = words.size();
        if (ww[0] != ww[1] && ww[0] != ww[2]) return words[0];
        for (int i = 1; i < N; ++i) {
            if (ww[0] != ww[i]) return words[i];
        }
        return {};
    }
};

