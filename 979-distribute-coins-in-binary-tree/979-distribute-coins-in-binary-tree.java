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
    public int distributeCoins(TreeNode root) {
        excess(root);
        return ans;
    }
    int excess(TreeNode node){
        if(node == null)
            return 0;
        int left = excess(node.left);
        int right = excess(node.right);
        ans += Math.abs(left) + Math.abs(right);
        return node.val + left + right - 1;
    }
}