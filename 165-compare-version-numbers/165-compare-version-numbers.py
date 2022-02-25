class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        revision1 = list(map(int, version1.split('.')))
        revision2 = list(map(int, version2.split('.')))
        
        n = len(revision1)
        m = len(revision2)
        
        i = 0
        while i < min(m, n):
            if revision1[i] > revision2[i]:
                return 1
            elif revision1[i] < revision2[i]:
                return -1
            i += 1
        
        while i < n:
            if(revision1[i] > 0):
                return 1
            i += 1
            
        while i < m:
            if revision2[i] > 0:
                return -1
            i += 1
            
        return 0
        
                
            
            
            