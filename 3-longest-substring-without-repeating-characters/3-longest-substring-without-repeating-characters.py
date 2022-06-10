class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        i, j = 0, 0
        ans = 0
        
        while j < len(s):
            if s[j] not in freq or freq[s[j]] == 0:
                freq[s[j]] = 1
                j += 1
            else:
                freq[s[i]] -= 1
                i += 1
            ans = max(ans, j-i)
        
        return ans