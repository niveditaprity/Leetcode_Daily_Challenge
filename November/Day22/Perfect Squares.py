
class Solution:
    def numSquares(self, n: int) -> int:
        squares = set([i ** 2 for i in range(1, int(sqrt(n)) + 1)])
        if n in squares:
            return 1
        
        seen = set(squares)
        q = deque([(sq, 1) for sq in squares])
        
        while q:
            item, depth = q.popleft()
            for sq in squares:
                newSum = sq + item
                if newSum <= n and newSum not in seen:
                    if newSum == n:
                        return depth + 1
                    seen.add(newSum)
                    q.append((newSum, depth + 1))
                    
