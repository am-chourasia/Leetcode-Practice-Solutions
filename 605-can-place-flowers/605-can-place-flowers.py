class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        continuous, flowers = 0, 0
        foundOne = False
        
        for bed in flowerbed:
            if bed is 0:
                continuous += 1
            else:
                if continuous > 0:
                    if foundOne:
                        flowers += (continuous - 1) // 2
                    else:
                        flowers += (continuous) // 2
                foundOne = True
                continuous = 0

        if foundOne:
            flowers += continuous // 2
        else:
            flowers += (continuous + 1) // 2
        
        return flowers >= n