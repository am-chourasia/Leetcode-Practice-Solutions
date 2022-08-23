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
    public boolean isPalindrome(ListNode head) {
        Stack<ListNode> stack = new Stack<ListNode>();
        ListNode slow = head, fast = head;
        stack.add(slow);
        
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            stack.add(slow);
            fast = fast.next.next;
        }
        
        ListNode current = slow.next;
        if (fast.next == null)
            stack.pop();
        
        while (!stack.empty()) {
            ListNode top = stack.pop();
            if(top.val != current.val)
                return false;
            current = current.next;
        }
        
        return true;
    }
}