class Solution {
    bool isPrime(int n) {
        int bound = sqrt(n) + 1;
        for (int f = 2; f < n && f <= bound; ++f) {
            if (n % f == 0) return false;
        }
        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        primes.push_back(0);
        for (int n = 2; n <= 1100; ++n) {
            if (isPrime(n)) {
                primes.push_back(n);
            }
        }
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        for (int i = 1; i <= n; ++i) {
            if (nums[i] <= nums[i - 1]) return false;
            auto fnd = lower_bound(primes.begin(), primes.end(), nums[i]);
            if (*fnd >= nums[i]) --fnd;
            while (nums[i] - *fnd <= nums[i - 1]) {
                if (fnd == primes.begin()) {
                    nums[i] += *fnd;
                    break;
                } else {
                    --fnd;
                }
            }
            nums[i] -= *fnd;
            cout << nums[i] << ' ';
        }
        cout << endl;
        return true;
    }
};

