# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        
        if root is None:
            return root
        
        def search(key):
            node = root
            parentNode = None
            # if root node is the node to be deleted:
            if node.val == key:
                return parentNode, node
            while node is not None:
                if key > node.val:
                    parentNode = node
                    node = node.right
                elif key < node.val:
                    parentNode = node
                    node = node.left
                else:
                    return parentNode, node
            return None, None # key node is not found
        
        def changeParentPointers(parentNode, newChild):
            if parentNode.left is not None and parentNode.left.val == key:
                parentNode.left = newChild
            else:
                parentNode.right = newChild
                
        parentNode, node = search(key)
        
        # if the key is not found:
        if parentNode is None and node is None:
            return root
        
        if node.right is None and node.left is None:
            if parentNode is None:
                root = None
            else:
                changeParentPointers(parentNode, None)
        elif node.right is not None:
            leftmost = node.right
            while leftmost.left is not None:
                leftmost = leftmost.left
            leftmost.left = node.left
            if parentNode is None:
                root = node.right
            else:
                changeParentPointers(parentNode, node.right)
        else:
            if parentNode is None:
                root = node.left
            else:
                changeParentPointers(parentNode, node.left)
        
        return root
        