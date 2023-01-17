class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(n: int) -> int:
            ret = 0
            while n != 0:
                ret = ret * 10 + n % 10
                n //= 10
            return ret
        MOD = 10**9 + 7
        c = Counter()
        ans = 0
        for n in nums:
            a = n - rev(n)
            c[a] += 1
            ans = (ans + c[a] - 1) % MOD
        return ans

