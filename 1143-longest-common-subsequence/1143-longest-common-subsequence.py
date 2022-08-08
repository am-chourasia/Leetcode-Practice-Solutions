class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1 = len(text1)
        len2 = len(text2)
        if len1 > len2:
            len1, len2 = len2, len1
            text1, text2 = text2, text1
            
        upperRow = [0 for i in range(len1 + 1)]
        lowerRow = [0 for i in range(len1 + 1)]
        
        for i in range(1, len2 + 1):
            for j in range(1, len1 + 1):
                if text2[i - 1] == text1[j - 1]:
                    lowerRow[j] = upperRow[j - 1] + 1
                else:
                    lowerRow[j] = max(upperRow[j], lowerRow[j - 1])
            upperRow, lowerRow = lowerRow, upperRow
        
        return upperRow[len1]
                    