class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        mods = [0] * 60
        for t in time:
            mods[t % 60] += 1
    
        countPairs = 0
        for mod in range(1, 60):
            if mod != 30:
                countPairs += (mods[mod] * mods[60 - mod])
        
        # accounting for the pairs taken twice:
        countPairs //= 2
        # pairing with mod of itself for 0 and 30:
        countPairs += (mods[0] * (mods[0] - 1)) // 2
        countPairs += (mods[30] * (mods[30] - 1)) // 2
        
        return countPairs