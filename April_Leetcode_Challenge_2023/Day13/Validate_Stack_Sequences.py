class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        i = 0
        for ele in pushed:
            stack.append(ele)
            while stack and stack[-1] == popped[i]:
                stack.pop()
                i+=1
        return i == len(popped)
