# Brute Force (TLE on second last test case)
class Solution:
    def removeDuplicates(self, s: str) -> str:
        if len(s) == 1:
            return s

        def helper(s):
            p1 = 0
            p2 = 1
            s = list(s)
            flag = True
            while p2 < len(s):
                if s[p1] == s[p2]:
                   flag = False
                   s[p1] = ''
                   s[p2] = ''
                   p1 += 2
                   p2 += 2
                else:
                    p1 += 1
                    p2 += 1 

            return ("".join(s), flag)
        
        out, flg = helper(s)
        
        while not flg:
            out, flg = helper(out)
        
        return out
