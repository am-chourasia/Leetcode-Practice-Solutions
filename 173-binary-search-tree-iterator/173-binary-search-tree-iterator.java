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
class BSTIterator {
    Set<TreeNode> isThreaded;
    TreeNode current = null;
    TreeNode deepRoot = null;
    
    private void inorder(TreeNode node, TreeNode parent){
        if(node == null)
            return;
        if(node.left == null && node.right == null){
            node.right = parent;
            isThreaded.add(node);
            return;
        }
        inorder(node.left, node);
        if(node.right == null){
            node.right = parent;
            isThreaded.add(node);
            return;
        }
        inorder(node.right, parent);
    }
    
    public BSTIterator(TreeNode root) {
        isThreaded = new HashSet<TreeNode>();
        current = new TreeNode(-1);
        deepRoot = current;
        current.right = root;
        inorder(root, current);
    }
    
    public int next() {
        if(isThreaded.contains(current)){
            current = current.right;
        } else {
            current = current.right;
            while(current.left != null)
                current = current.left;
        }
        return current.val;
    }
    
    public boolean hasNext() {
        if(current == null || current.right == deepRoot)
            return false;
        return true;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */