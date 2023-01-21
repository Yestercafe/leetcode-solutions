class Solution {
    using ll = long long;
public:
    bool isReachable(ll tx, ll ty) {
        for (ll t = 0; t < 1e10; ++t) {
            while (tx % 2 == 0) tx /= 2;
            while (ty % 2 == 0) ty /= 2;
            if (tx < ty) {    // tx > ty
                swap(tx, ty);
            }
            tx += ty;
            while (tx % 2 == 0) tx /= 2;
            while (ty % 2 == 0) ty /= 2;
            if (tx == 1 || ty == 1) return true;
            if (tx == ty) return false;
        }
        return false;
    }
};

