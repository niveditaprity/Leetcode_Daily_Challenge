# using utility functions (29ms - faster than 98%)
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        s = " ".join(s[::-1])
        return s

 
# using stack (39ms - faster than 87%)
class Solution:
    def reverseWords(self, s: str) -> str:
        stack = []
        
        currentWord = ''
        
        # if character is a space in the beginning of the string
        # without any actual word yet (like "   hello" then ignore it (pass)
        
        # if character is a space in the middle, then push the currently
        # formed to stack and reset it to ''
        
        # if the character isnt a space, just add to current word
        for i in range(len(s)):
            if s[i] == ' ' and currentWord == '':
                pass
            elif s[i] == ' ':
                stack.append(currentWord)
                currentWord = ''
            else:
                currentWord += s[i]
        
        # push the last word to stack only if its not a trailing space
        if currentWord != '':
            stack.append(currentWord)

        out = ''
        
        while stack:
            word = stack.pop()
            if word != '':
                out += word
            
            # add a space between words except the last word
            if len(stack) > 0:
                out += ' '
        
        return out
