// *
//  * Definition for a binary tree node.
//  * public class TreeNode {
//  *     int val;
//  *     TreeNode left;
//  *     TreeNode right;
//  *     TreeNode() {}
//  *     TreeNode(int val) { this.val = val; }
//  *     TreeNode(int val, TreeNode left, TreeNode right) {
//  *         this.val = val;
//  *         this.left = left;
//  *         this.right = right;
//  *     }
//  * }

class Node{
    TreeNode node;
    int distance;
    Node(TreeNode node, int distance){
        this.node = node;
        this.distance = distance;
    }
}
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root.left == root.right)
            return 1;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(root, 1));
        
        int ans = 0;
        
        while(!queue.isEmpty()){
            int size = queue.size();
            int first = -1, last = -1;
            for(int i = 0; i < size; i++){
                Node current = queue.poll();
                TreeNode currentNode = current.node;
                int distance = current.distance;
                if(i == 0)
                    first = distance;
                last = distance;
                if(currentNode.left != null)
                    queue.offer(new Node(currentNode.left, distance * 2));
                if(currentNode.right != null)
                    queue.offer(new Node(currentNode.right, distance * 2 + 1));
            }
            ans = Math.max(ans, last - first + 1);
        }
        
        return ans;
    }
}