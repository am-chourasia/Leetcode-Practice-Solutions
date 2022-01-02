class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        
        asteroids.sort()
        addedMass = mass
        
        for astMass in asteroids:
            if astMass <= addedMass:
                addedMass += astMass
            else:
                return False
        
        return True