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
    public boolean isSymmetric(TreeNode root) {
        inverse(root.right);
        Queue<TreeNode> leftTree = new LinkedList<TreeNode>();
        Queue<TreeNode> rightTree = new LinkedList<TreeNode>();
        
        if(root.left != null)
            leftTree.offer(root.left);
        if(root.right != null)
            rightTree.offer(root.right);
        
        while(!leftTree.isEmpty() && !rightTree.isEmpty()){
            TreeNode node1 = leftTree.poll();
            TreeNode node2 = rightTree.poll();
            if(node1.val != node2.val)
                return false;
            if(node1.left == null && node2.left == null)
                ; // eat five start do nothing
            else if(node1.left == null || node2.left == null)
                return false;
            else{
                leftTree.offer(node1.left);
                rightTree.offer(node2.left);
            }
            if(node1.right == null && node2.right == null)
                ; // eat five start do nothing
            else if(node1.right == null || node2.right == null)
                return false;
            else{
                leftTree.offer(node1.right);
                rightTree.offer(node2.right);
            }
        }
        
        if(!leftTree.isEmpty() || !rightTree.isEmpty())
            return false;
        return true;
    }
    void inverse(TreeNode node){
        if(node == null)
            return;
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
        inverse(node.left);
        inverse(node.right);
    }
}