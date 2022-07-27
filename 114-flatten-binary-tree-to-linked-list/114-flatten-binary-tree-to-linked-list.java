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
    private TreeNode flattenUtility(TreeNode root){
        if(root == null)
            return root;
        TreeNode attachNode = flattenUtility(root.left);
        TreeNode rightNode = root.right;
        if(attachNode != null) {
            root.right = root.left;
            root.left = null;
            attachNode.right = rightNode;
        }
        TreeNode last = flattenUtility(rightNode);
        if(last != null)
            return last;
        if(attachNode != null)
            return attachNode;
        return root;
    }
    public void flatten(TreeNode root) {
        flattenUtility(root);
    }
}