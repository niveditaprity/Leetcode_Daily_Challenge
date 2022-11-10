 # For Loop
  class Solution:
    def removeDuplicates(self, s: str) -> str:
        
        res=[]
        for i in s:
            if res and res[-1]==i:
                res.pop()
            else:
                res.append(i)
                
        return "".join(res) 
      
# While Loop
class Solution:
    def removeDuplicates(self, s: str) -> str:
        
        res = []
        n = len(s)
        i = 0
        
        while(i < n):
            if res and res[-1] == s[i]:
                res.pop()
            else:
                res.append(s[i])
            i += 1
            
        return ''.join(res) 
