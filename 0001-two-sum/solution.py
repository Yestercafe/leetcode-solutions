class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = Counter()
        for i, a in enumerate(nums):
            if target - a in m:
                return [i, m[target - a]]
            m[a] = i

