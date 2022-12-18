class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        s2 = ""
        for i, v in c.most_common():
            for j in range(v):
                s2 += i
        return s2

class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join([i for i,v in Counter(s).most_common() for j in range(v)])


# without using Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        char_freq = {}
        for i in s:
            if i not in char_freq:
                char_freq[i] = 1
            else:
                char_freq[i] += 1

        sorted_by_freq = sorted(char_freq.items(), key=lambda x: x[1], reverse=True)
        
        sorted_string = ""
        for ch, fq in sorted_by_freq:
            for j in range(fq):
                sorted_string += ch
        return sorted_string