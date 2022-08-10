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
    TreeNode constructTree(int[] nums, int left, int right){
        if(left >= right)
            return null;
        int mid = (right + left) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = constructTree(nums, left, mid);
        root.right = constructTree(nums, mid + 1, right);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int len = nums.length;
        return constructTree(nums, 0, len);
    }
}