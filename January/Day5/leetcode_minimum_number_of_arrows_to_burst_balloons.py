class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])
        prev = points[0]

        count = 1
        for curr in range(1, len(points)):
            if points[curr][0]>prev[1]:
                count += 1
                prev = points[curr]
            else: #Overlapping
                prev[0] = max(points[curr][0], prev[0])
                prev[1] = min(points[curr][1], prev[1])
        return count