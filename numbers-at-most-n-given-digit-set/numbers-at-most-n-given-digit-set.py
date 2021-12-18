class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        
        digits = [int(digit) for digit in digits]
        number = str(n)
        orderOfN = len(number) - 1
        digitsAvailable = len(digits)
        
        ans = 0
        
        # for numbers having less digits than n,
        # we have all the digits available at every place value
        # adding which forms a GP sequence
        # (a * (r^n - 1)) / (r - 1)   ----- GP sequence
        multiplier = digitsAvailable ** orderOfN
        if digitsAvailable > 1:
            ans = (int(multiplier - 1) * digitsAvailable) // (digitsAvailable - 1)
        else:
            ans = orderOfN
            
        includesInvalidDigit = False
        
        for digit in number:
            dig = int(digit)
            choices = bisect_left(digits, dig)
            ans += choices * multiplier
            multiplier //= digitsAvailable
            # if the digit is not present in the allowed digits array, break out
            if choices == digitsAvailable or digits[choices] != dig:
                includesInvalidDigit = True
                break
        
        if not includesInvalidDigit:
            ans += 1 # adding one for the number itself
        return ans