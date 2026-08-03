class Solution:
    def stoneGameIII(self, nums: List[int]) -> str:
        @cache
        def dp(i):
            if i == len(nums):
                return 0
            first = nums[i] - dp(i + 1)
            first2 = first
            first3 = first
            if i + 1 < len(nums):
                first2 = nums[i] + nums[i+1] - dp(i + 2)
            if i + 2 < len(nums):
                first3 = nums[i] + nums[i+1] + nums[i+2] - dp(i + 3)
            return max(max(first, first2), first3)
        ans = dp(0)
        if ans > 0:
            return "Alice"
        elif ans == 0:
            return "Tie"
        return "Bob"