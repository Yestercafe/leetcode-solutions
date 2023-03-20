class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        n = str(n)
        @cache
        def dfs(i, mask, is_limit, is_num, is_dup):
            if i == len(n):
                return int(is_num and is_dup)
            ret = 0
            if not is_num:
                ret = dfs(i + 1, mask, False, is_num, is_dup)
            bound = int(n[i]) if is_limit else 9
            for d in range(int(not is_num), bound + 1):
                if ((mask >> d) & 1) == 1:
                    ret += dfs(i + 1, mask, is_limit and d == bound, True, True)
                else:
                    ret += dfs(i + 1, mask | (1 << d), is_limit and d == bound, True, is_dup)
            return ret
        return dfs(0, 0, True, False, False)

