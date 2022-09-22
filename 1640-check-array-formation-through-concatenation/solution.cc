class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> idxs;
        int flat_len = 0;
        for (int i = 0; i < pieces.size(); ++i) {
            auto& p = pieces[i];
            flat_len += p.size();
            idxs[p[0]] = i;
        }
        if (flat_len != arr.size()) return false;
        
        int cur = 0;
        for (int c = 0; c < pieces.size(); ++c) {
            map<int, int>::const_iterator f;
            if ((f = idxs.find(arr[cur])) == idxs.cend()) {
                return false;
            }
            
            int p = f->second;
            for (int i = 0; i < pieces[p].size(); ++i) {
                if (arr[cur++] != pieces[p][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

