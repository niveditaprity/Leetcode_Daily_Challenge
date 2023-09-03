
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:

        income = collections.defaultdict(list)

        for src,dst in edges:
            income[dst].append(src)

        res = []
        for i in range(n):
            if not income[i]:
                res.append(i)

        return res
        
