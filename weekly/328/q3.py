class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        ans = left = pairs = 0
        for x in nums:
            pairs += cnt[x]
            cnt[x] += 1
            ans += left
            while pairs >= k:
                ans += 1
                cnt[nums[left]] -= 1
                pairs -= cnt[nums[left]]
                left += 1
        return ans
