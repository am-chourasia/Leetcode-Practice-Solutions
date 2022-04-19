/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode firstElement = null;
    TreeNode secondElement = null;
    TreeNode prevNode = new TreeNode(Integer.MIN_VALUE);
    
    public void recoverTree(TreeNode root) {
        traverse(root);
        int temp = firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val = temp;
    }

    private void traverse(TreeNode node){
        if(node == null)
            return;
        traverse(node.left);
        
        if(prevNode.val > node.val){
            if(firstElement == null)
                firstElement = prevNode;
            if(firstElement != null)
                secondElement = node;
        }
        
        prevNode = node;
        traverse(node.right);
    }
}