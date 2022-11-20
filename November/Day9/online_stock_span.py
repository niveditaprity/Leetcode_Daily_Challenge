# brute force (TLE on test case 86/99)
class StockSpanner:
    def __init__(self):
        self.prices = []

    def next(self, price: int) -> int:
        self.prices.append(price)
        count = 0
        
        for i in range(len(self.prices) - 1, -1, -1):
        
            if self.prices[i] <= price:
                count += 1
            else:
                break
        
        return count


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)


# using stack
class StockSpanner:
    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        if not self.stack:
            item = (price, 1)
            self.stack.append(item)
            return 1
        
        count = 1
        
        while self.stack and self.stack[-1][0] <= price:
            _, oldCount = self.stack.pop()
            count += oldCount
        
        newItem = (price, count)
        self.stack.append(newItem)
        
        return count

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
