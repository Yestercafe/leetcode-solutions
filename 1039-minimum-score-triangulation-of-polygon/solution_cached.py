class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @cache
        def dfs(i, j):
            if i == j or i + 1 == j:
                return 0
            ans = inf
            for k in range(i + 1, j):
                a = dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]
                if ans > a: ans = a
            return ans
        return dfs(0, len(values) - 1)

