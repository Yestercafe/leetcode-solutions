class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        self.n = n
        self.index = index
        self.maxSum = maxSum

        left, right = 0, maxSum + 1
        def check(m: int) -> bool:
            l = index
            r = n - 1 - l
            def cal(a: int) -> int:
                nonlocal m
                if a < m - 1:
                    return (m - a + m - 1) * a // 2
                else:
                    return m * (m - 1) // 2 + (a - m + 1)
            return m + cal(l) + cal(r) <= maxSum
        
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                left = mid
            else:
                right = mid;
        return left

