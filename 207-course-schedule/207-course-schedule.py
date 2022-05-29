class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        WHITE, GREY, BLACK = 0, 1, 2
        graph = [[] for i in range(numCourses)]
        
        for course, preCourse in prerequisites:
            graph[preCourse].append(course)
            
        color = [WHITE for i in range(numCourses)]
        
        def isCyclic(node):
            color[node] = GREY
            for neighbour in graph[node]:
                if color[neighbour] is GREY:
                    return True
                if color[neighbour] is WHITE and isCyclic(neighbour):
                    return True
            color[node] = BLACK
            return False
        
        for i in range(numCourses):
            if color[i] is WHITE:
                if isCyclic(i):
                    return False
        
        return True
        