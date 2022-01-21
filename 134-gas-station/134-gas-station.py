class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        n = len(gas)
        diff, count = 0, 0
        
        for j in range(2*n):
            i = j % n
            diff += gas[i] - cost[i]
            count += 1
            if diff < 0:
                diff = 0
                count = 0
            if count == n:
                return (j + 1) % n
        
        return -1