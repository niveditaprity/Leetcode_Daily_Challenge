class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # if len are not equal then return False
        if len(word1) != len(word2):
            return False
        
        sorted_w1 = sorted(word1)
        sorted_w2 = sorted(word2)
        # compare if all characters are same return True
        if sorted_w1 == sorted_w2:
            return True
        
        # using counter to cout frequency (MAP)
        s1 = Counter(sorted_w1)
        s2 = Counter(sorted_w2)

        # if keys and overall frequecy values are equal (mapping doesn't matter) then return True 
        if (s1.keys() == s2.keys()) and (sorted(s1.values()) == sorted(s2.values())):
            return True
        return False