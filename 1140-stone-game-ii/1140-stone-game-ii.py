class Solution:
    def stoneGameII(self, nums: List[int]) -> int:
        for i in range(len(nums) - 2, -1, -1):
            nums[i] += nums[i+1]
        @cache
        def dp(i, M):
            if 2 * M + i >= len(nums):
                return nums[i]
            return nums[i] - min(dp(i + j, max(j, M)) for j in range(1, 2 * M + 1))
        return dp(0, 1)