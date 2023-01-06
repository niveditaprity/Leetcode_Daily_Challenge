class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        heapq.heapify(costs)
        count = 0
        while(coins>0 and costs):
            min_el = heapq.heappop(costs)
            if min_el <= coins:
                coins -= min_el
                count += 1
            else:
                break
        return count