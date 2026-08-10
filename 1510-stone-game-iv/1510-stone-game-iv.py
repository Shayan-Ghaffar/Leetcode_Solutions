class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False] * n
        dp.append(False)
        squares = [j * j for j in range(1, int(n ** 0.5) + 1)]
        for i in range(1, n + 1):
            for sq in squares:
                if sq > i:
                    break
                if sq <= i:
                    if dp[i - sq] == False:
                        dp[i] = True
                        break
        return dp[n]
