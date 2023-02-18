class Solution {
public:
    int minMaxDifference(int num) {
        auto s = to_string(num);
        int maxx = -1, minn = INT_MAX;
        for (int r = 0; r < 10; ++r) {
            auto ns = s;
            for (auto& c : ns) {
                if (c == r + '0') c = '9';
            }
            maxx = max(maxx, stoi(ns));
        }
        for (int r = 0; r < 10; ++r) {
            auto ns = s;
            for (auto& c : ns) {
                if (c == r + '0') c = '0';
            }
            minn = min(minn, stoi(ns));
        }
        cout << maxx << ' ' << minn << endl;
        return maxx - minn;
    }
};

