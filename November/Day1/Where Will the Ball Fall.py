# Method : Dynamic Programming

#from functools import cache

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        #@cache
        def helper(i, j):
            if i == m:
                return j
            if grid[i][j] == 1:
                if j==n-1 or grid[i][j+1]==-1:
                    return -1
                return helper(i+1, j+1)
            if grid[i][j] == -1:
                if j==0 or grid[i][j-1]==1:
                    return -1
                return helper(i+1, j-1)
        return [helper(0,j) for j in range(n)]
