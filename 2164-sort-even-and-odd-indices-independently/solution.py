class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        oi, ei = [], []
        o, e = [], []
        for i, n in enumerate(nums):
            if i % 2 == 0:
                ei.append(i)
                e.append(n)
            else:
                oi.append(i)
                o.append(n)

        o.sort(reverse = True)
        e.sort()
        io, ie = 0, 0
        for i, n in enumerate(o):
            nums[oi[i]] = n
        for i, n in enumerate(e):
            nums[ei[i]] = n
        return nums

