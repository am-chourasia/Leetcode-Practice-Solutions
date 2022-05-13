/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Node start = root;
        while(start != null){
            Node node = start;
            Node prev = null;
            
            while(node != null){
                if(prev == null){
                    if(node.left != null)
                        prev = start = node.left;
                    else if(node.right != null)
                        prev = start = node.right;
                }
                
                if(node.left != null){
                    prev.next = node.left;
                    prev = node.left;
                }
                if(node.right != null){
                    prev.next = node.right;
                    prev = node.right;
                } 
                
                node = node.next;
            }
            if(prev != null)
                prev.next = null;
            else
                start = null;
        }
        return root;
    }
}