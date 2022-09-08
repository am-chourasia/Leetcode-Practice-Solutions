# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        traversal = []
        if root is None:
            return traversal
        
        stack = []
        current = root
        while current is not None or len(stack) > 0: 
            while current is not None:
                stack.append(current)
                current = current.left
            current = stack.pop()
            traversal.append(current.val)
            current = current.right
            
        return traversal