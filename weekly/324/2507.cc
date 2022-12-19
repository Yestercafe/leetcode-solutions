class Solution {
public:
    int smallestValue(int n) {
        set<int> cycle_chk;
        cycle_chk.insert(n);

        int minn = n;
        int nn = n;
        do {
            int sn = 0;
            for (int f = 2; f <= nn; ++f) {
                while (nn % f == 0) {
                    sn += f;
                    nn /= f;
                }
            }
            if (cycle_chk.find(sn) != cycle_chk.end()) {
                break;
            }
            // cout << sn << endl;
            cycle_chk.insert(sn);
            minn = min(minn, sn);
            nn = sn;
        } while (true);
        
        return minn;
    }
};

