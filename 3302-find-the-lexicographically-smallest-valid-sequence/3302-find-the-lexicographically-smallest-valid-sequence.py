class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n, m = len(word1), len(word2)
        suff = [-1] * m
        j = m - 1
        for i in range(n - 1, -1, -1):
            if word1[i] == word2[j]:
                suff[j] = i
                j -= 1
            if j < 0: break
        change = False
        j = 0
        res = []
        for i in  range(0, n, 1):
            if j == m: break
            if word1[i] == word2[j]:
                res.append(i)
                j += 1
            elif not change and (j == m - 1 or suff[j + 1] > i):
                res.append(i)
                j += 1
                change = True
        if len(res) == m:
            return res
        return []