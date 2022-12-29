class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        c = Counter(set(nums1)) + Counter(set(nums2)) + Counter(set(nums3))
        return [i for i, cnt in c.items() if cnt >= 2]

