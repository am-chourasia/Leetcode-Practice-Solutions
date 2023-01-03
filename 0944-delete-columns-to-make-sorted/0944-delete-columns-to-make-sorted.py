class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        size = len(strs)
        length = len(strs[0])
        count = 0
        
        for col in range(length):
            lastChar = 'a'
            for string in strs:
                if string[col] < lastChar:
                    count += 1
                    break
                lastChar = string[col]
        
        return count