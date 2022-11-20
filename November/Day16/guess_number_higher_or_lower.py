# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


# solution based on binary search
# time complexity: O(nlogn)
# space complexity: O(1)
class Solution:
    def guessNumber(self, n: int) -> int:
        start = 1
        end = n

        while True:
            mid = start + (end - start) / 2

            guessRes = guess(mid)

            if guessRes == -1:
                end = mid - 1

            elif guessRes == 1:
                start = mid + 1
            
            else:
                return int(mid)
