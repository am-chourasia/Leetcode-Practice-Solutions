# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        
        self.dummyNode = None
        self.head = None
        
        def inorder(node):
            if node is None:
                return
            
            inorder(node.left)
            node.left = None
            
            if self.dummyNode is None:
                self.head = node
            else:
                self.dummyNode.right = node
                            
            self.dummyNode = node
            inorder(node.right)
        
        inorder(root)
        return self.head