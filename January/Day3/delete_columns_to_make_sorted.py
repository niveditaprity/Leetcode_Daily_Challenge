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


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:

        count = 0
        for row in range(len(strs[0])):
            for col in range(1, len(strs)):
                if strs[col][row] < strs[col-1][row]:
                    count += 1
                    break
        return count