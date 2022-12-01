# One liner solution using "Counter"

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        return len(c := Counter(arr)) == len(set(c.values()))