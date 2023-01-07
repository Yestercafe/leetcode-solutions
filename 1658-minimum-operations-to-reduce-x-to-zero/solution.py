class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        s = sum(nums)
        if s < x: return -1

        ls, rs = 0, s
        ans = inf
        r = 0
        for l in range(-1, n):
            if l != -1:
                ls += nums[l]
            while r < n and ls + rs > x:
                rs -= nums[r]
                r += 1
            if ls + rs == x:
                ans = min(ans, (l + 1) + (n - r))
        
        return ans if ans != inf else -1

