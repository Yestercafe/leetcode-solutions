class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        p = sum(nums) + target
        if p < 0 or p % 2 != 0:
            return 0
        p //= 2

        ks = [0] * (p + 1)
        ks[0] = 1
        for i in range(n):
            for j in range(p, nums[i] - 1, -1):
                ks[j] += ks[j - nums[i]]
        
        return ks[p]

