class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) return num;
        auto sn = to_string(num);
        int i = 1;
        while (i != sn.length() && sn[i - 1] >= sn[i])
            ++i;
        if (i == sn.length()) return num;
        int mi = i;
        while (i != sn.length()) {
            if (sn[mi] <= sn[i]) {
                mi = i;
            }
            ++i;
        }
        i = mi;
        int j = 0;
        while (j != sn.length() && sn[i] <= sn[j])
            ++j;
        swap(sn[i], sn[j]);
        return stoi(sn);
    }
};

