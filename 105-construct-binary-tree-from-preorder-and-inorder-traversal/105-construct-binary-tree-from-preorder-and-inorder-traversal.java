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
    int index;
    Map<Integer, Integer> inorderIndex;
    private TreeNode constructTree(int left, int right, int[] inorder, int[] preorder){
        if(left > right)
            return null;
        int nodeValue = preorder[index];
        index++;
        int nodeIndex = inorderIndex.get(nodeValue);
        TreeNode node = new TreeNode(nodeValue);
        node.left = constructTree(left, nodeIndex - 1, inorder, preorder);
        node.right = constructTree(nodeIndex + 1, right, inorder, preorder);
        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        index = 0;
        inorderIndex = new HashMap<Integer, Integer>();
        int n = inorder.length;
        for(int i = 0; i < n; i++)
            inorderIndex.put(inorder[i], i);
        
        return constructTree(0, n - 1, inorder, preorder);
    }
}