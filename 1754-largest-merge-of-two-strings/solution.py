class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        i, j = 0, 0
        n, m = len(word1), len(word2)
        ans = []
        while i < n or j < m:
            if i < n and word1[i:] > word2[j:]:
                ans.append(word1[i])
                i += 1
            else:
                ans.append(word2[j])
                j += 1
        return ''.join(ans)

