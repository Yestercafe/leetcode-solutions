class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left, right = 1, max(nums)
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            s = sum((x - 1) // mid for x in nums)
            if s <= maxOperations:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans

