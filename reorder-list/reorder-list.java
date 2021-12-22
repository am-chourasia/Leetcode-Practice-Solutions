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
    public void reorderList(ListNode head) {
        if(head.next == null || head.next.next == null)
            return;
        
        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy, fast = dummy;
        
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        ListNode mid = slow;
        Stack<ListNode> stack = new Stack<>();
        while(slow.next != null){
            slow = slow.next;
            stack.push(slow);
        }
        
        mid.next = null;
        slow = head;
        ListNode poped = null;
        while(!stack.empty()){
            poped = stack.pop();
            poped.next = slow.next;
            slow.next = poped;
            slow = (poped.next == null) ? poped : poped.next;
        }
    }
}