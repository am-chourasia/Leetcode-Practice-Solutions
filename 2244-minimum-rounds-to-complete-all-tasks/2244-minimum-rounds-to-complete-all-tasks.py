class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        taskCount = {}
        for task in tasks: 
            if task in taskCount:
                taskCount[task] += 1
            else:
                taskCount[task] = 1
        
        minimumRounds = 0
        for count in taskCount.values():
            if count < 2:
                return -1
            minimumRounds += count // 3
            if count % 3 != 0:
                minimumRounds += 1
        
        return minimumRounds
            