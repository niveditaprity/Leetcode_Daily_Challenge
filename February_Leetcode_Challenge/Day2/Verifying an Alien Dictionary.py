
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:

        lookup = {c:ind for ind,c in enumerate(order)}

        word2 = []
        for w in words:
            temp = []
            for c in w:
                temp.append(lookup[c])
            word2.append(temp)

        for i in range(1, len(word2)):
            if word2[i-1] > word2[i]:
                return False
        return True
        
