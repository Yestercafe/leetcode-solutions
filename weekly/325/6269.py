class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if not target in words:
            return -1
        n = len(words)
        ws = words * 3
        startIndex += n
        ans1, ans2 = 0, 0
        for i in range(startIndex, -1, -1):
            if ws[i] == target:
                break
            ans1 += 1
        for i in range(startIndex, 3 * n):
            if ws[i] == target:
                break
            ans2 += 1
        return min(ans1, ans2)

