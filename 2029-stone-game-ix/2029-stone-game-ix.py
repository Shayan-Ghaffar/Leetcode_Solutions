class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        c0 = 0
        c1 = 0
        c2 = 0
        for i in stones:
            if i % 3 == 0:
                c0 += 1
            elif i % 3 == 1:
                c1 += 1
            elif i % 3 == 2:
                c2 += 1
        if c0 % 2:
            return abs(c1 - c2) > 2
        return c1 > 0 and c2 > 0