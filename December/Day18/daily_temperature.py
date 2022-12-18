class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0]*len(temperatures)
        stack = []
        n = len(temperatures)
        for i in range(len(temperatures)-1, -1, -1):
            while(stack and temperatures[stack[-1]] <= temperatures[i]):
                stack.pop()
            if not stack:
                ans[i] = 0
            else:
                ans[i] = stack[-1]-i
            stack.append(i)
        return ans