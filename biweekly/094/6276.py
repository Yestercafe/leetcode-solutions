class Solution:
    def countAnagrams(self, s: str) -> int:
        mole, deno = 1, 1
        MOD = 10 ** 9 + 7
        for w in s.split():
            cnt = Counter()
            for i, c in enumerate(w):
                cnt[c] += 1
                mole = mole * (i + 1) % MOD
                deno = deno * cnt[c] % MOD
        return mole * pow(deno, -1, MOD) % MOD

