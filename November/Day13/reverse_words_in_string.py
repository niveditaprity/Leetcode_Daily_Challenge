# using utility functions (29ms - faster than 98%)
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        s = " ".join(s[::-1])
        return s
