class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        ans = 0
        VOWELS = 'aeiou'
        for i in range(left, right + 1):
            if words[i][0] in VOWELS and words[i][-1] in VOWELS:
                ans += 1
        return ans

