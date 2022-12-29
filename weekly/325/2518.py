class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        if sum(nums) < 2 * k:
            return 0

        ks = [0] * k
        ks[0] = 1
        for x in nums:
            for j in range(k - 1, x - 1, -1):
                ks[j] = (ks[j] + ks[j - x]) % MOD
        return (pow(2, len(nums), MOD) - sum(ks) * 2) % MOD

