class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        s = []
        @cache
        def generate(left, right, st):
            if left == 0 and right == 0:
                s.append(st)
                return
            if left < right:
                generate(left, right - 1, st + ')')
            if left > 0:
                generate(left - 1, right, st + '(')
        generate(n,n,"")
        return s