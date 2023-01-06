HIGH = 14

class TrieNode:
    def __init__(self):
        self.child = [None, None]
        self.c = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add(self, x: int) -> None:
        curr = self.root
        for i in range(HIGH, -1, -1):
            b = (x >> i) & 1
            if not curr.child[b]:
                curr.child[b] = TrieNode()
            curr = curr.child[b]
            curr.c += 1

    def get(self, n: int, x: int) -> int:
        ans = 0
        curr = self.root
        for i in range(HIGH, -1, -1):
            b = (n >> i) & 1
            if (x >> i) & 1:
                if curr.child[b]:
                    ans += curr.child[b].c
                if not curr.child[b ^ 1]:
                    return ans
                curr = curr.child[b ^ 1]
            else:
                if not curr.child[b]:
                    return ans
                curr = curr.child[b]
        ans += curr.c
        return ans

class Solution:
    def countPairs(self, nums: List[int], low: int, high: int) -> int:
        def f(nums: List[int], x: int) -> int:
            ans = 0
            t = Trie()
            for i in range(1, len(nums)):
                t.add(nums[i - 1])
                ans += t.get(nums[i], x)
            return ans
        return f(nums, high) - f(nums, low - 1)

