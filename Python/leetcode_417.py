class Solution(object):

    def ans_func(i):
        if i % 3 == 0 and i % 5 == 0:
            return "FizzBuzz"


        if i % 3 == 0:
            return "Fizz"
        if i % 5 == 0:
            return "Buzz"
        

    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        return [self.ans_func(i) for i in range(1, i+1)]