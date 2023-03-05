class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = time % (n - 1);
        bool rev = time / (n - 1) % 2;
        if (rev) {
            return n - pos;
        } else {
            return 1 + pos;
        }
    }
};

