class Solution:
    def numSquares(self, n: int) -> int:
        sq = []
        upper_bound = int(math.sqrt(n))
        if upper_bound * upper_bound == n:
            return 1
        for i in range(1, upper_bound + 1):
            sq.append(i * i)

        dp = []
        for i in range(n + 1):
            dp.append(i)
        for i in range(1, n + 1):
            for j, p in enumerate(sq):
                if i - p < 0:
                    break
                dp[i] = min(dp[i], dp[i - p] + 1)
        return dp[-1]

