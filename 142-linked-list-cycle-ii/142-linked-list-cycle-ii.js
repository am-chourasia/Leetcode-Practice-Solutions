/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    if(head == null)
        return null;
    let slow = head, fast = head;
    
    while(fast !== null && fast.next !== null){
        slow = slow.next;
        fast = fast.next.next;
        if(fast == slow)
            break;
    }
    if(fast == null || fast.next == null)
        return null; // no cycle

    slow = head;
    while(slow !== fast){
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
};