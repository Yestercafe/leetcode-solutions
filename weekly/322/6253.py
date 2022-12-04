def equivalent(c1, c2):
    return ord(c1) == ord(c2) # or ord(c1) - 32 == ord(c2) or ord(c1) == ord(c2) - 32 # 加了后面这个简直脑子冲昏了

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        s = sentence.split()
        r = True
        for i in range(len(s) - 1):
            if not equivalent(s[i][-1], s[i + 1][0]):
                r = False
                break
        if not equivalent(s[0][0], s[-1][-1]):
            r = False
        return r
