class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        e, o = nums[::2], nums[1::2]
        o.sort(reverse=True)
        e.sort()
        for i in range(len(o)):
            nums[2 * i] = e[i]
            nums[2 * i + 1] = o[i]
        if len(nums) % 2: nums[-1] = e[-1]
        return nums

