class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        for i in range(n):
            s1, s2 = set(nums[:i+1]), set(nums[i+1:])
            ans.append(len(s1) - len(s2))
        return ans

