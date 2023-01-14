class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        c = Counter(tasks)
        count = 0
        for key, value in c.items():
            if value == 1:
                return -1
            if value%3 == 0:
                count += value//3
            else:
                count += value//3 + 1
        return count