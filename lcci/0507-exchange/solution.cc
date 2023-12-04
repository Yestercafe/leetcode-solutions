class Solution {
    void helper(unsigned n) {
        if (n == 0) return;
        helper(n / 2);
        cout << n % 2;
    }

public:
    int exchangeBits(int num_) {
        unsigned num = static_cast<unsigned>(num_);
        helper(num);
        endl(cout);
        for (int i = 0; i < 32; i += 2) {
            int last2 = (num >> i) & 3;
            switch (last2) {
                case 0: case 3:
                    break;
                case 1:    // 01 -> 10
                    num |= (1 << (i + 1));   // 0 -> 1
                    num ^= (1 << i);         // 1 -> 0
                    break;
                case 2:
                    num ^= (1 << (i + 1));
                    num |= (1 << i);
                    break;
            }
        }
        helper(num);
        endl(cout);
        return static_cast<int>(num);
    }
};

