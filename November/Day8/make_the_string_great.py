# brute force
class Solution:
    def makeGood(self, s: str) -> str:
        def checkGood(s):
            s = list(s)
            flag = True
            for i in range(len(s) - 1):
                if s[i].lower() == s[i+1].lower():
                    if (s[i].islower() and s[i+1].isupper()) or (s[i].isupper() and s[i+1].islower()):
                        flag = False
                        s[i] = ''
                        s[i+1] = ''
            
            return ("".join(s), flag)
        
        response, isGood = checkGood(s)

        while not isGood:
            response, isGood = checkGood(response)
        return response
 
 
 
# cleaner brute force
class Solution:
    def makeGood(self, s: str) -> str:
        def checkGood(s):
            s = list(s)
            flag = True
            for i in range(len(s) - 1):
                    if s[i] == s[i+1].swapcase():
                        flag = False
                        s[i] = ''
                        s[i+1] = ''
            
            return ("".join(s), flag)
        
        response, isGood = checkGood(s)

        while not isGood:
            response, isGood = checkGood(response)
        return response
        


# using stack
class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if stack and stack[-1] == s[i].swapcase():
                stack.pop()
            else:
                stack.append(s[i])
            
        return "".join(stack)
        
# Easy String
class Solution:
    def makeGood(self, s: str) -> str:
        st = []
        for i in s:
            if len(st) == 0:
                st.append(i)
            else:
                if st[-1].lower() == i.lower() and st[-1] != i:
                    st.pop()
                else:
                    st.append(i)
        return "".join(st)
