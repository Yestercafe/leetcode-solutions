class Solution {
public:
    int splitNum(int num) {
        string ns = to_string(num);
        sort(ns.begin(), ns.end());
        int a = 0, b = 0;
        int n = ns.length();
        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                a = a * 10 + (ns[i] - '0');
            } else {
                b = b * 10 + (ns[i] - '0');
            }
        }
        return a + b;
    }
};

