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
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left == right)
            return head;
        
        ListNode start = null, end = null;
        ListNode current = head, prevHead = null;
        int index = 1;
        
        while(true){
            if(index == left){
                end = current;
                ListNode next = null, prev = null;
                while(index != right + 1){
                    next = current.next;
                    current.next = prev;
                    prev = current;
                    current = next;
                    index += 1;
                    if(index == right)
                        start = current;
                }
                break;
            }
            prevHead = current;
            current = current.next;
            index += 1;
        }
        
        end.next = current;
        if(prevHead == null)
            return start;
        
        prevHead.next = start;
        return head;
    }
}