# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        
        node = root
        
        # Find the right place to insert the node:
        while True:
            # traverse according to the ordering unless no further traversal is possible
            if val > node.val:
                if node.right is not None:
                    node = node.right
                else:
                    break
            else:
                if node.left is not None:
                    node = node.left
                else:
                    break
        
        # insert the node
        if node.val > val:
            node.left = TreeNode(val)
        else:
            node.right = TreeNode(val)
        
        return root