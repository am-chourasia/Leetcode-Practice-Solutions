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
    int sum;
    int maxDepth;
    public int deepestLeavesSum(TreeNode root) {
        maxDepth = sum = 0;
        dfs(root, 1);
        return sum;
    }
    void dfs(TreeNode root, int depth){
        if(root == null)
            return;
        if(depth > maxDepth){
            sum = 0;
            maxDepth = depth;
        }
        if(depth == maxDepth)
            sum += root.val;
        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
}