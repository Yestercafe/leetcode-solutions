class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        ranges::sort(box);
        vector<int> f(box.size());
        for (int i = 0; i < n; ++i) {
            f[i] = box[i][2];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
                    f[i] = max(f[i], f[j] + box[i][2]);
                }
            }
        }

        return *ranges::max_element(f);
    }
};

