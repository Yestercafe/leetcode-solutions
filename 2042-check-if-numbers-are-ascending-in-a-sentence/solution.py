class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        s = s.split()
        l = []
        for i in s:
            try:
                l.append(int(i))
            except:
                pass
        
        for i in range(1, len(l)):
            if l[i - 1] >= l[i]:
                return False
        return True

