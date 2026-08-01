class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        @cache
        def dp(i, j, alice, score):
            if i > j:
                return score >= 0
            pick = 0
            nPick = 0
            if alice:
                pick = dp(i + 1, j, False, score + nums[i])
                nPick = dp(i, j - 1, False, score + nums[j])
                return pick or nPick
            else:
                pick = dp(i + 1, j, True, score - nums[i])
                nPick = dp(i, j - 1, True, score - nums[j])
                return pick and nPick

        alice = 0
        return dp(0, len(nums) - 1, True, alice)
