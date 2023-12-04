class Solution {
    using u64 = unsigned long long;
public:
    int insertBits(int n, int m, int i, int j) {
        u64 un = static_cast<u64>(n), um = static_cast<u64>(m);

        um <<= i;
        un = ((((1 << i) - 1) & un) | (un >> (j + 1) << (j + 1)));

        return static_cast<int>(un | um);
    }
};

