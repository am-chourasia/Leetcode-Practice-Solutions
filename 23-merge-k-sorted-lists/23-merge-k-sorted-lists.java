/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class NodeComparator implements Comparator<ListNode>{
    public int compare(ListNode l1, ListNode l2) {
        int a = l1.val, b = l2.val;
        if (a > b)
            return 1;
        else if (a < b)
            return -1;
        return 0;
    }
}
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        if(n == 0)
            return null;
        Queue<ListNode> pq = new PriorityQueue<>(n, new NodeComparator());
        for(ListNode root : lists)
            if(root != null)
                pq.offer(root);
        
        ListNode head = pq.poll();
        ListNode it = head;
        if(head != null && head.next != null)
            pq.offer(head.next);
        
        while(!pq.isEmpty()){
            ListNode node = pq.poll();
            it.next = node;
            it = node;
            if(node.next != null)
                pq.offer(node.next);
        }
        return head;
    }
}