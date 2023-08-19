class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        for i in range(2, n + 1):
            c = 1
            t = ""
            s += '&'
            for j in range(1, len(s)):
                if s[j] == s[j - 1]:
                    c += 1
                else:
                    t += str(c)
                    t += s[j - 1]
                    c = 1
            s = t
        return s