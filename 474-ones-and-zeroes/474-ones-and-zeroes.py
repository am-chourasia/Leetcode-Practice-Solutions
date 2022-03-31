class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        length = len(strs)
        dp = [[[None for j in range(n + 1)] for i in range(m + 1)] for k in range(length + 1)]
        ans = 0
        freq = [None] * length
        
        for i in range(length):
            string = strs[i]
            zeroes = 0
            ones = 0
            for character in string:
                if character is '0':
                    zeroes += 1
                else:
                    ones += 1
            freq[i] = (zeroes, ones)
                
        def find(i, allowed_zeroes, allowed_ones):
            if i >= length or (allowed_zeroes <= 0 and allowed_ones <= 0):
                return 0
            if dp[i][allowed_zeroes][allowed_ones] is not None:
                return dp[i][allowed_zeroes][allowed_ones]
            zero, one = freq[i]
            dp[i][allowed_zeroes][allowed_ones] = find(i + 1, allowed_zeroes, allowed_ones)
            if zero <= allowed_zeroes and one <= allowed_ones:
                chosen = 1 + find(i + 1, allowed_zeroes - zero, allowed_ones - one)
                dp[i][allowed_zeroes][allowed_ones] = max(dp[i][allowed_zeroes][allowed_ones], chosen)
            return dp[i][allowed_zeroes][allowed_ones]
        
        for i in range(length):
            zero, one = freq[i]
            ans = max(ans, find(i, m, n))
        
        return ans