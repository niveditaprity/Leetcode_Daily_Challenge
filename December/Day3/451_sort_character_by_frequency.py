class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        s2 = ""
        for i, v in c.most_common():
            for j in range(v):
                s2 += i
        return s2

