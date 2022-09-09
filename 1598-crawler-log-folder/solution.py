class Solution:
    def minOperations(self, logs: List[str]) -> int:
        depth = 0
        for log in logs:
            stride = log.split('/')
            for d in stride:
                if len(d) == 0: continue
                if d == '..':
                    if depth > 0:
                        depth -= 1
                elif d != '.':
                    depth += 1
        return depth

