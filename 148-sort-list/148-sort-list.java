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
class CustomComparator implements Comparator<ListNode> {
    public int compare(ListNode a, ListNode b){
        return a.val - b.val;
    }
}
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null)
            return head;
        Queue<ListNode> pq = new PriorityQueue<ListNode>(new CustomComparator());
        ListNode node = head;
        while(node != null){
            pq.offer(node);
            node = node.next;
        }
        ListNode newHead = pq.poll();
        ListNode newNode = newHead;
        while(!pq.isEmpty()){
            newNode.next = pq.poll();
            newNode = newNode.next;
        }
        newNode.next = null;
        return newHead;
    }
}