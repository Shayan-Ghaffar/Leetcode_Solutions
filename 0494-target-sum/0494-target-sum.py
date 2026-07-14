class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        @cache
        def ways(i, curr):
            if i == len(nums):
                if curr == target:
                    return 1
                else: return 0
            plus = 0
            minus = 0
            plus = ways(i + 1, curr + nums[i])
            minus = ways(i + 1, curr - nums[i])
            return plus + minus
        return ways(0, 0)
