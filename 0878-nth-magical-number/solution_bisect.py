class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        lcm = math.lcm(a, b)
        MOD = 10 ** 9 + 7
        return bisect_left(range(10 ** 18), n, key = lambda c: c // a + c // b - c // lcm) % MOD

