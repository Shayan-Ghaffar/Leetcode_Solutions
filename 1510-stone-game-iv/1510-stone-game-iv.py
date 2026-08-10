class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False] * n
        dp.append(False)
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                if j * j > i:
                    break
                if j * j <= i:
                    if dp[i - j * j] == False:
                        dp[i] = True
                        break
        return dp[n]
