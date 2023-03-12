class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(key=lambda x: -x)
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i - 1]
        ans = 0
        for i in range(n):
            if nums[i] <= 0: break
            ans += 1
        return ans

