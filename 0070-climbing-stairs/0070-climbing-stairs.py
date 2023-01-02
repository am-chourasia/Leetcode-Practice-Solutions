class Solution:
    def climbStairs(self, n: int) -> int:
        # 0 -> 1
        # 1 -> 1
        # 2 -> 2
        # 3 -> 3
        # 4 -> 5
        # 5 -> 8
        
        if n == 1:
            return 1
        
        prevStep = 1
        secondPrevStep = 1
        
        for i in range(2, n + 1):
            temp = prevStep
            prevStep = prevStep + secondPrevStep
            secondPrevStep = temp
            
        return prevStep
        