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
    int ans = 0;
    public int sumRootToLeaf(TreeNode root) {
        traverse(root, 0);
        return ans;
    }
    void traverse(TreeNode node, int n){
        if(node == null)
            return;
        n = (n << 1) + node.val;
        traverse(node.left, n);
        traverse(node.right, n);
        if(node.left == null && node.right == null){
            ans += n;
            return;
        }
    }
}