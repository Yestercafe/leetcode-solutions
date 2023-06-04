kclass Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        while len(num1) < len(num2):
            num1 = '0' + num1
        while len(num2) < len(num1):
            num2 = '0' + num2
        if num1 > num2:
            num1, num2 = num2, num1
        MOD = 10 ** 9 + 7
        @cache
        def dfs(i: int, s: int, is_dlim: bool, is_ulim: bool) -> int:
            if s > max_sum:
                return 0
            if i == len(num1):
                if min_sum <= s <= max_sum:
                    return 1
                return 0
            res = 0
            down = int(num1[i]) if is_dlim else 0
            up = int(num2[i]) if is_ulim else 9
            for d in range(down, up + 1):
                res = (res + dfs(i + 1, s + d, is_dlim and d == down, is_ulim and d == up)) % MOD
            return res % MOD
        return dfs(0, 0, True, True)

