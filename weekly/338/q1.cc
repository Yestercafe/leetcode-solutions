class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if (k > numOnes) {
            ans += numOnes;
            k -= numOnes;
        } else {
            return k;
        }
        
        if (k > numZeros) {
            k -= numZeros;
        } else {
            return ans;
        }
        
        return ans - k;
    }
};

