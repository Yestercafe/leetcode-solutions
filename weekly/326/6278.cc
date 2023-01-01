class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int ans = 0;
        int n = num;
        while (n) {
            if (num % (n % 10) == 0) ans++;
            n /= 10;
        }
        return ans;
    }
};

