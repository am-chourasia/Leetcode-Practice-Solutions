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
    int preorderIndex;
    Map<Integer, Integer> inorderIndex;
    private TreeNode constructTree(int left, int right, int[] preorder){
        if(left > right)
            return null;
        int nodeValue = preorder[preorderIndex++];
        int nodeIndex = inorderIndex.get(nodeValue);
        TreeNode node = new TreeNode(nodeValue);
        node.left = constructTree(left, nodeIndex - 1, preorder);
        node.right = constructTree(nodeIndex + 1, right, preorder);
        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        inorderIndex = new HashMap<Integer, Integer>();
        int n = inorder.length;
        for(int i = 0; i < n; i++)
            inorderIndex.put(inorder[i], i);
        
        return constructTree(0, n - 1, preorder);
    }
}