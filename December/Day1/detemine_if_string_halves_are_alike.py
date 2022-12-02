class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        # using set here so that 'in' operator takes O(1) to check vowel existancy.
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        mid = len(s)//2
        count_av, count_bv = 0, 0
        
        for i in range(mid):
            if s[i] in vowels:
                count_av += 1
            if s[mid+i] in vowels:
                count_bv += 1
        
        return count_av == count_bv