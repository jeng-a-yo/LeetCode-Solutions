class Solution:
    def isValid(self, s: str) -> bool:
        right_parentheses = [')', ']', '}']
        if len(s) % 2 == 1 or (s[0] in right_parentheses):
            return False
        stack = []
        for i in s:
            if len(stack) == 0 and i in right_parentheses:
                return False
            if i == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif i == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif i == '}':
                if stack[-1] == '{':
                    stack.pop()
                else:
                    return False
            else:
                stack.append(i)
        else:
            return stack == []

# ------------------------------------------------------------------------------

class Solution:
    def isValid(self, s: str) -> bool:
        parentheses_pair = {')': '(', ']': '[', '}': '{'}
        stack = []
        
        for char in s:
            if char in parentheses_pair:
                if stack and stack[-1] == parentheses_pair[char]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(char)
        
        return not stack

