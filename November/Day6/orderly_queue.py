# https://leetcode.com/problems/orderly-queue/description/

class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k > 1:
            return "".join(sorted(s))
        
        else:
            ans = s
            for _ in range(len(s)):
                s = s[1:] + s[0]
                ans = min(ans, s)
        
        return ans
