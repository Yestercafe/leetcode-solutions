class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        for (int i = m - 1; i >= 0; --i) {
            a[i + n] = a[i];
        }

        int i = n, j = 0, q = 0;
        while (i < m + n && j < n) {
            if (a[i] < b[j]) {
                a[q++] = a[i++];
            } else {
                a[q++] = b[j++];
            }
        }
        while (i < m + n) {
            a[q++] = a[i++];
        }
        while (j < n) {
            a[q++] = b[j++];
        }
    }
};

