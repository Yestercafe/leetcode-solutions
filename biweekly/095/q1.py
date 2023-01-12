class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        '''
        如果满足以下条件，那么箱子是 "Bulky" 的：
            箱子 至少有一个 维度大于等于 10^4 。
            或者箱子的 体积 大于等于 10^9 。
        如果箱子的质量大于等于 100 ，那么箱子是 "Heavy" 的。'''
        bulky, heavy = False, False
        if length >= 10**4 or width >= 10**4 or height >= 10**4 or length * width * height >= 10**9:
            bulky = True
        if mass >= 100:
            heavy = True
        
        if bulky and heavy:
            return 'Both'
        if not bulky and not heavy:
            return 'Neither'
        if bulky:
            return 'Bulky'
        return 'Heavy'

