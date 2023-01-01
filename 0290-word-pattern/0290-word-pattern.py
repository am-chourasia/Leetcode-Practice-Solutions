class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        forwardMatching = {}
        backwardMatching = {}
        words = s.split()
    
        length = len(pattern)
        if length != len(words):
            return False
        
        for i in range(len(pattern)):
            char = pattern[i]
            word = words[i]
            if char in forwardMatching and forwardMatching[char] != word:
                return False
            if word in backwardMatching and backwardMatching[word] != char:
                return False
            forwardMatching[char] = word
            backwardMatching[word] = char
        
        return True