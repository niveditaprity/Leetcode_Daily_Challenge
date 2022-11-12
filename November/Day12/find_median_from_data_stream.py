# Brute Force
class MedianFinder:

    def __init__(self):
        self.input = []

    def addNum(self, num: int) -> None:
        self.input.append(num)

    def findMedian(self) -> float:
        self.input.sort()
        
        mid = 0 + len(self.input) - 1
        mid = mid // 2

        if len(self.input) % 2 == 0:
            return (self.input[mid] + self.input[mid + 1]) / 2.0
        else:
            return self.input[mid]  
          
# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


# Cleaner Brute Force
class MedianFinder:

    def __init__(self):
        self.input = []
        self.isOdd = True

    def addNum(self, num: int) -> None:
        if self.isOdd and self.input:
            self.isOdd = False
        elif not self.isOdd:
            self.isOdd = True

        self.input.append(num)      
            
    def findMedian(self) -> float:
        self.input.sort()

        mid = 0 + len(self.input) - 1
        mid = mid // 2

        if not self.isOdd:
            return (self.input[mid] + self.input[mid + 1]) / 2.0
        else:
            return self.input[mid] 

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


# Two Heaps
class MedianFinder:

    def __init__(self):
        self.maxHeap = []
        self.minHeap = []

    def addNum(self, num: int) -> None:
        heappush(self.maxHeap, -num)

        heappush(self.minHeap, -heappop(self.maxHeap))

        if len(self.minHeap) > len(self.maxHeap):
            heappush(self.maxHeap, -heappop(self.minHeap))

    def findMedian(self) -> float:
        if len(self.minHeap) == len(self.maxHeap):
            return (self.minHeap[0] - self.maxHeap[0]) / 2.0
        
        else:
            return -self.maxHeap[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
