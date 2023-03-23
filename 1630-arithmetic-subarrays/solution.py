vclass Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        intervals = zip(l, r)
        ans = []
        for i, (l, r) in enumerate(intervals):
            slice = nums[l:r+1]
            slice.sort()
            if len(slice) < 2:
                ans.append(True)
                continue
            diff = slice[1] - slice[0]
            flag = True
            for i in range(1, len(slice) - 1):
                if slice[i + 1] - slice[i] != diff:
                    flag = False
                    break
            ans.append(flag)
        return ans

