class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        n = len(price)

        def check(d: int) -> bool:
            cnt = 1
            p = price[0]
            for a in price:
                if p + d <= a:
                    cnt += 1
                    p = a
            return cnt >= k

        left, right = 0, (price[-1] - price[0]) // (k - 1) + 1
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):  # 符合所以答案还不够大
                left = mid
            else:
                right = mid
        return left

