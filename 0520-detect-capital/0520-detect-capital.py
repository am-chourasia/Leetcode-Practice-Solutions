class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        allUpper = word.upper()
        allLower = word.lower()
        capitalize = word.capitalize()
        
        if allUpper == word or allLower == word or capitalize == word:
            return True
        return False