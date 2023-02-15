class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        return [r := sum(map(lambda x: x // 2, Counter(nums).values())), len(nums) - 2 * r]

