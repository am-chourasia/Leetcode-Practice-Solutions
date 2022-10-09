# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], target: int) -> bool:
        def isPresent(node, value, skipNode):
            if node is None:
                return False
            if node.val == value and node is not skipNode:
                return True
            if value > node.val:
                return isPresent(node.right, value, skipNode)
            return isPresent(node.left, value, skipNode)
        
        def traverse(node):
            if node is None:
                return False
            required = target - node.val
            if isPresent(root, required, node):
                return True
            return traverse(node.left) or traverse(node.right)
        
        return traverse(root)