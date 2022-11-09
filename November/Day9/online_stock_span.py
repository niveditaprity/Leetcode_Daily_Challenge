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
