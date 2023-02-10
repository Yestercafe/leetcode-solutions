class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10**9 + 7
        @cache
        def dfs(i, prev, rem):
            if i == n:
                return 1
            ans = 0
            for j in range(6):
                if j != prev:
                    ans = (ans + dfs(i + 1, j, rollMax[j] - 1)) % MOD
                elif rem > 0:
                    ans = (ans + dfs(i + 1, prev, rem - 1)) % MOD
            return ans;
        return dfs(0, -1, -1) % MOD

