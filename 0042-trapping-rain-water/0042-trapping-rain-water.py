class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxLeft = -1
        maxRight = -1
        total = 0
        while left < right:
            maxLeft = max(height[left], maxLeft)
            maxRight = max(height[right], maxRight)
            if height[left] <= height[right]:
                total = total + (maxLeft - height[left])
                left += 1
            else:
                total = total + (maxRight - height[right])
                right -= 1
        return total