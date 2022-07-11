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
    private void dfs(TreeNode node, int level, List<Integer> rightView){
        if (node == null)
            return;
        int size = rightView.size();
        if(level >= size)
            rightView.add(node.val);
        else
            rightView.set(level, node.val);
        dfs(node.left, level + 1, rightView);
        dfs(node.right, level + 1, rightView);
    }
    public List<Integer> rightSideView(TreeNode root) {
        var rightView = new ArrayList<Integer>();
        if (root == null)
            return rightView;
        
        dfs(root, 0, rightView);
        return rightView;
    }
}