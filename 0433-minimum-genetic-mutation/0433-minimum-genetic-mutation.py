class Solution:
    def _checkOneMismatch(self, mutation1, mutation2):
        mismatch = 0
        for i in range(len(mutation1)):
            if mutation1[i] is not mutation2[i]:
                mismatch += 1
        return mismatch == 1
    
    def _buildGraph(self, graph, bank):
        size = len(bank)
        for i in range(size):
            for j in range(i + 1, size):
                if self._checkOneMismatch(bank[i], bank[j]):
                    graph[i].append(j)
                    graph[j].append(i)
                    
    def _minPath(self, graph, target):
        size = len(graph)
        visited = [False for _ in range(size)]
        queue = deque()
        queue.append(size - 1)
        visited[size - 1] = True
        steps = 0

        while queue:
            steps += 1
            queueSize = len(queue)
            for _ in range(queueSize):
                currentMutation = queue.popleft()
                for possibleMutation in graph[currentMutation]:
                    if possibleMutation is target:
                        return steps
                    if not visited[possibleMutation]:
                        visited[possibleMutation] = True
                        queue.append(possibleMutation)
        return -1
    
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        
        target = -1
        for i in range(len(bank)):
            if end == bank[i]:
                target = i;
                break
        
        if target < 0:
            return -1
        
        bank.append(start)
        size = len(bank)
        graph = [[] for _ in range(size)]
        self._buildGraph(graph, bank)
        
        return self._minPath(graph, target)