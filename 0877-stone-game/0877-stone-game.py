class Solution:
    def stoneGame(self, nums: List[int]) -> bool:
        @cache
        def dp(i, j):
            if i == j:
                return nums[i]
            leftPick = nums[i] - dp(i + 1, j)
            rightPick = nums[j] - dp(i, j - 1)
            return max(leftPick, rightPick)
        return dp(0, len(nums) - 1) > 0