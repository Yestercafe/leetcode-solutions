class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        auto req = 0;
        const int N = blocks.size();
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++req;
            }
        }
        int min_req = req;
        for (int i = k; i < N; ++i) {
            if (blocks[i - k] == 'B') ++req;
            if (blocks[i] == 'B') --req;
            min_req = min(min_req, req);
        }

        return min_req;
    }
};

