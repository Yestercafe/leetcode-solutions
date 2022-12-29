class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        p = sum(nums) + target
        if p < 0 or p % 2 != 0:
            return 0
        p /= 2

        @cache
        def dfs(i: int, s: int):
            if i < 0:
                return 1 if s == 0 else 0
            return dfs(i - 1, s) + dfs(i - 1, s - nums[i])
        
        return dfs(len(nums) - 1, p)

