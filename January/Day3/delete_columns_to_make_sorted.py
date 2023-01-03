class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:

        count = 0
        for row in range(len(strs[0])):
            s = []
            for col in range(len(strs)):
                s.append(strs[col][row])

            if sorted(s) != s:
                count += 1
        return count