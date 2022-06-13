class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        votes = [0] * (n+1)
        
        for trustor, trustee in trust:
            votes[trustee] += 1     # increase the vote of the trustee that can be a judge
            votes[trustor] = -10000 # judge cannot trust anyone, so trustor can't be a judge
        
        for i in range(1,n+1):
            if votes[i] == n-1:
                return i
        
        return -1