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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null)
            return list2;
        if(list2 == null)
            return list1;
        ListNode it1 = list1, it2 = list2;
        ListNode head = null;
        if(it1.val < it2.val){
            head = it1;
            it1 = it1.next;
        } else {
            head = it2;
            it2 = it2.next;
        }
        
        ListNode node = head;
        
        while(it1 != null && it2 != null){
            if(it1.val < it2.val){
                node.next = it1;
                it1 = it1.next;
            } else {
                node.next = it2;
                it2 = it2.next;
            }
            node = node.next;
        }
        while(it1 != null){
            node.next = it1;
            it1 = it1.next;
            node = node.next;
        }
        while(it2 != null){
            node.next = it2;
            it2 = it2.next;
            node = node.next;
        }
        return head;
    }
}