class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        majority = -1
        for i in nums:
            if count is 0:
                majority = i
            if i == majority:
                count += 1
            else:
                count -= 1
        return majority