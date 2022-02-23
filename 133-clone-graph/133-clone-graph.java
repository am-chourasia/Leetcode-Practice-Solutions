/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    Map<Integer, Node> map; 
    Node traverseAndClone(Node root){
        Node current = new Node(root.val);
        map.put(root.val, current);
        Node neighbour;
        for(Node node : root.neighbors){
            if(map.containsKey(node.val))
                neighbour = map.get(node.val);
            else
                neighbour = traverseAndClone(node);
            current.neighbors.add(neighbour);
        }
        return current;
    }
    public Node cloneGraph(Node node) {
        if(node == null)
            return null;
        map = new HashMap<Integer, Node>();
        return traverseAndClone(node);
    }
}