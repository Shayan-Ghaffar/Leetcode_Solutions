class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        su = 0
        for i in nums:
            su = su + i
        if su % 2 == 1:
            return False
        half = su / 2
        curr = 0
        @cache
        def knapSack(i, curr):
            if i == len(nums):
                if curr == half:
                    return True
                return False
            if curr == half:
                return True
            if curr > half:
                return False
            return knapSack(i + 1, curr + nums[i]) or knapSack(i + 1, curr)
        return knapSack(0, curr)
