class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        presum = 0
        len_n = len(nums)
        min_avg = float("inf")
        min_key = None
        for i, v in enumerate(nums):
            presum += v
            ab1 = presum//(i+1)
            divs = len_n-i-1
            if divs <=0:
                ab2 = total_sum - presum
            else:
                ab2 = (total_sum - presum)// divs
            abs_diff = abs(ab1-ab2)
            if abs_diff< min_avg:
                min_avg = abs_diff
                min_key = i
        return min_key