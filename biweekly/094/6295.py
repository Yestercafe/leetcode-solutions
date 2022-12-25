class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        lcm = math.lcm(divisor1, divisor2)
        def check(k: int):
            d1 = uniqueCnt1 - (k // divisor2 - k // lcm)
            d2 = uniqueCnt2 - (k // divisor1 - k // lcm)
            comm = k - (k // divisor1 + k // divisor2 - k // lcm)
            return comm >= max(d1, 0) + max(d2, 0)
        
        left, right = 0, 10 ** 18
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid
        return right

