class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suf = [0] * n
        sum = 0
        for i in range(-1, - n - 1, -1):
            sum += piles[i]
            suf[i] = sum

        @cache
        def dfs(i, m):
            if i + 2 * m >= n:
                return suf[i]
            return suf[i] - min(dfs(i + x, max(m, x)) for x in range(1, min(2 * m + 1, n - i)))
            
        return dfs(0, 1)

