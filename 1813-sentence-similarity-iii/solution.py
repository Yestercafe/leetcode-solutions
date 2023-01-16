class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        if len(sentence1) < len(sentence2):
            sentence1, sentence2 = sentence2, sentence1
        s1 = sentence1.split()
        s2 = sentence2.split()
        n1, n2 = len(s1), len(s2)
        for left in range(n2 + 1):
            if left == n2: break
            if s1[left] != s2[left]: break
        for right in range(n2 + 1):
            if right == n2: break
            if left + right == n2: break
            if s1[n1 - 1 - right] != s2[n2 - 1 - right]: break
        if left + right == n2: return True
        return False

