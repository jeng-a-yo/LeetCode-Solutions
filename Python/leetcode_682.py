class Solution:
    def calPoints(self, operations: List[str]) -> int:
        ans_opeprations = []
        for operation in operations:
            if operation == '+':
                ans_opeprations.append(ans_opeprations[-1] + ans_opeprations[-2])
            elif operation == 'D':
                ans_opeprations.append(ans_opeprations[-1] * 2)
            elif operation == 'C':
                ans_opeprations.pop()
            else:
                ans_opeprations.append(int(operation))
            

        return sum(ans_opeprations)
