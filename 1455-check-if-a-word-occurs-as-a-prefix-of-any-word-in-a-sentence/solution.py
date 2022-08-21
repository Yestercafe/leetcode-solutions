class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        s = sentence.split()
        idx = -2
        for i in range(len(s)):
            if s[i].startswith(searchWord):
                idx = i
                break
        return idx + 1

