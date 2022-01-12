# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def validSequence(self) -> bool:
        if not self.traversalStarted:
            self.traversalStarted = True
            self.prevNode = self.currentNode
            return True
        isValid: bool = self.prevNode.val < self.currentNode.val
        self.prevNode = self.currentNode
        return isValid
        
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.traversalStarted: bool = False
        self.prevNode: TreeNode = None
        self.currentNode: TreeNode = root
            
        # Morris Traversal: 
        
        while self.currentNode is not None:
            if self.currentNode.left is None:
                if not self.validSequence():
                    return False
                self.currentNode = self.currentNode.right
            else:
                rightmost = self.currentNode.left
                while rightmost.right is not None and rightmost.right is not self.currentNode:
                    rightmost = rightmost.right
                    
                if rightmost.right is None:
                    rightmost.right = self.currentNode
                    self.currentNode = self.currentNode.left
                else:
                    rightmost.right = None
                    if not self.validSequence():
                        return False
                    self.currentNode = self.currentNode.right
        
        return True