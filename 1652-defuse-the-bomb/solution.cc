class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int N = code.size();
        if (k == 0) return vector<int>(N, 0);
        
        vector<int> v(N, 0);
        if (k > 0) {
            int window = 0;
            for (int i = 0; i < k; ++i) {
                window += code[1 + i];
            }
            for (int i = 0; i < N; ++i) {
                v[i] = window;
                window -= code[(1 + i) % N];
                window += code[(1 + i + k) % N];
            }
        } else {
            k = -k;
            int window = 0;
            for (int i = 0; i < k; ++i) {
                window += code[N - 1 - i];
            }
            for (int i = 0; i < N; ++i) {
                v[i] = window;
                window -= code[(N + i - k) % N];
                window += code[i % N];
            }
        }
        return v;
    }
};

