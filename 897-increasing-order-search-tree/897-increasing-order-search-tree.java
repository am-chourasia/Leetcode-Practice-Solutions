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
    TreeNode head;
    TreeNode dummy;
    public TreeNode increasingBST(TreeNode root) {
        head = dummy = null;
        inorder(root);
        return head;
    }
    private void inorder(TreeNode node){
        if(node == null)
            return;
        inorder(node.left);
        node.left = null;
        
        if(dummy == null)
            head = node;
        else
            dummy.right = node;
        
        dummy = node;
        inorder(node.right);
    }
}