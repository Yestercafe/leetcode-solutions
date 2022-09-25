class Solution {
public:
    int rotatedDigits(int n) {
        // 3 4 7 / 0 1 8
        
        int good_cnt = 0;
        
        for (int a = 1; a <= n; ++a) {
            int n = a;
            bool valid = true, inc = false;
            while (n != 0) {
                int tail = n % 10;
                if (tail == 3 || tail == 4 || tail == 7) {
                    valid = false;
                    break;
                } if (tail == 2 || tail == 5 || tail == 6 || tail == 9) {
                    inc = true;
                }
                n /= 10;
            }
            if (valid && inc) {
                ++good_cnt;
            }
        }
        
        return good_cnt;
        
    }
};

