class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        length = len(tokens)
        if length == 0:
            return 0
        
        tokens.sort()
        i, j = 0, length - 1
        
        score = 0
        while i < j:
            if power >= tokens[i]:
                power -= tokens[i]
                score += 1
                i += 1
            elif score >= 1:
                power += tokens[j]
                score = score - 1
                j -= 1
            else:
                break
        
        # i == j
        if power >= tokens[i]:
            score += 1
        
        return score