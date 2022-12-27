class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        j = n
        c = Counter()
        while c['a'] < k or c['b'] < k or c['c'] < k:
            if j == 0:
                return -1
            j -= 1
            c[s[j]] += 1
        
        ans = n - j
        for i, e in enumerate(s):
            c[e] += 1
            while j < n and c[s[j]] > k:
                c[s[j]] -= 1
                j += 1
            ans = min(ans, i + 1 + n - j)
            if j >= n:
                break
        return ans

