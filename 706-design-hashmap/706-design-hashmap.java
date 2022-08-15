class ListNode{
    int key, val;
    ListNode next;
    public ListNode(int key, int val){
        this.key = key;
        this.val = val;
    }
    public ListNode find(int keyToFind){
        ListNode node = this, prev = null;
        while(node != null && node.key != keyToFind){
            prev = node;
            node = node.next;
        }
        return prev;
    }
}

class MyHashMap {
    final ListNode[] nodes = new ListNode[10_000];
    
    int idx(int key) {
        return Integer.hashCode(key) % nodes.length;
    }

    public void put(int key, int value){
        int i = idx(key);
        if(nodes[i] == null)
            nodes[i] = new ListNode(-1, -1);
        ListNode prev = nodes[i].find(key);
        if(prev.next == null)
            prev.next = new ListNode(key, value);
        else 
            prev.next.val = value;
    }

    public int get(int key){
        int i = idx(key);
        if(nodes[i] == null)
            return -1;
        ListNode prev = nodes[i].find(key);
        ListNode node = prev.next;
        return node == null ? -1 : node.val;
    }

    public void remove(int key){
        int i = idx(key);
        if(nodes[i] != null){
            ListNode prev = nodes[i].find(key);
            if(prev.next != null)
                prev.next = prev.next.next;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */