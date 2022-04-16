# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        
        def recurse(node):
            if node is None:
                return None
            if node.val < low:
                return recurse(node.right)
            elif node.val > high:
                return recurse(node.left)
            else:
                node.left = recurse(node.left)
                node.right = recurse(node.right)
            return node
        
        return recurse(root)