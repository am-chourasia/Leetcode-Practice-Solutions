# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        self.summation = 0
        
        def traverse(node):
            if node is None:
                return
            
            traverse(node.right)
            self.summation += node.val
            node.val = self.summation
            traverse(node.left)
        
        traverse(root)
        return root