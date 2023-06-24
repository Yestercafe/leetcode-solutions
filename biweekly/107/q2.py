class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        def max3(a, b, c):
            if a >= b and a >= c:
                return a
            if b >= a and b >= c:
                return b
            if c >= a and c >= b:
                return c
        @cache
        def dfs(prev: int, x: int, y: int, z: int) -> int:
            if x < 0 or y < 0 or z < 0:
                return -1
            if prev < 0:
                return max3(dfs(0, x-1, y, z), dfs(1, x, y-1, z), dfs(2, x, y, z-1)) + 1
            elif prev == 0:
                return max3(-inf, -inf, dfs(1, x, y-1, z)) + 1
            elif prev == 1:
                return max3(-inf, dfs(0, x-1, y, z), dfs(2, x, y, z-1)) + 1
            else:
                return max3(-inf, dfs(0, x-1, y, z), dfs(2, x, y, z-1)) + 1
        return dfs(-1, x, y, z) * 2

