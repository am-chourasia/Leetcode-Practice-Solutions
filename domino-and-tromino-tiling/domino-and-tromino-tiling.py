class Solution:
    def numTilings(self, n: int) -> int:
        if n <= 2:
            return n
        mod = 1000000007
        
        f = [0]*(n+1)
        p = [0]*(n+1)
        
        f[1], f[2] = 1, 2
        p[1], p[2] = 0, 1
        
        for k in range(3, n+1):
            f[k] = (f[k-1] + f[k-2] + 2 * p[k-1])%mod
            p[k] = (p[k-1] + f[k-2]) % mod
        
        return f[n]