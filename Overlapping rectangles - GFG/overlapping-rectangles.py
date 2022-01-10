#User function Template for python3

class Solution:
    
    def doOverlap(self, L1, R1, L2, R2):
        x1, y1 = L1
        x2, y2 = R1
        p1, q1 = L2
        p2, q2 = R2
        if x1 < p1 < x2 and (y2 <= q1 <= y1 or y2 <= q2 <= y1 or q1 >= y1 >= q2):
            return 1
        if p1 < x1 < p2 and (q2 <= y1 <= q1 or q2 <= y2 <= q1 or y1 >= q1 >= y2):
            return 1
        return 0
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        p=[0]*2
        q=[0]*2
        r=[0]*2
        s=[0]*2
        p[0],p[1],q[0],q[1],r[0],r[1],s[0],s[1]=map(int,input().strip().split(" "))
        ob=Solution()
        ans=ob.doOverlap(p,q,r,s)
        print(ans)
# } Driver Code Ends