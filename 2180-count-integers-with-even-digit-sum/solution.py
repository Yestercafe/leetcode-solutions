class Solution:
    def countEven(self, num: int) -> int:
        def f(x: int) -> int:
            return sum([ord(i) - ord('0') for i in str(x)]) % 2
        return num - sum([f(i) for i in range(1, num + 1)])

