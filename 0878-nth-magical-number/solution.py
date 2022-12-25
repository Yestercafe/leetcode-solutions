# 二分答案
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        lcm = math.lcm(a, b)
        MOD = 10 ** 9 + 7
        def cal(c: int):
            div_a = c // a
            div_b = c // b
            div_lcm = c // lcm
            return div_a + div_b - div_lcm
        
        left, right = 0, 10 ** 18
        # 这里使用双开区间的二分答案，
        # 可能主要是因为方便，不需要做过多的加减
        # 闭区间的二分也可以：
        '''
        left, right = 0, 10 ** 18
        while left <= right:
            mid = (left + right) // 2
            if cal(mid) < n:
                left = mid + 1
            else:   # cal(mid) > n or cal(mid) == n
                right = mid - 1
        return (right + 1) % MOD
        '''
        while left + 1 < right:
            mid = (left + right) // 2
            if cal(mid) < n:
                left = mid
            # 即使 cal == n 也要更新 right，这是为了
            # 找到 lower_bound
            else:
                right = mid
        # 想一下，最终闭区间范围内的最右侧，一定是比 n 小的那个数
        # 于是开区间范围内的 right 一定就是最小的符合 n 的那个解
        return right % MOD

