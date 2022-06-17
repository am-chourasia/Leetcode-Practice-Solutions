# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countRequirement(self, node):
        if node is None:
            return 0
        left = self.countRequirement(node.left)
        right = self.countRequirement(node.right)
        
        if left > 0 or right > 0:     
            # subtrees require current node to have camera
            self._ans += 1
            return -1
        if left < 0 or right < 0:     
            # current node has been covered 
            # and there is no reuirement in either of the subtrees
            return 0
        
        # no requirement in the subtrees 
        # but current node is not covered
        return 1
    
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        self._ans = 0
        if self.countRequirement(root) > 0:
            self._ans += 1
        return self._ans
        
                