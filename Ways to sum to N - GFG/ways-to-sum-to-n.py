#User function Template for python3

class Solution:
    def countWays(self, arr, size, target):
        dp = [0] * (target + 1)
        dp[0] = 1
        mod = 1000000007
        for i in range(1, target+1):
            for coin in arr:
                if coin <= i:
                    dp[i] = (dp[i] + dp[i - coin]) % mod
        
        
        return dp[target]
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        m,n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.countWays(arr, m, n))
# } Driver Code Ends