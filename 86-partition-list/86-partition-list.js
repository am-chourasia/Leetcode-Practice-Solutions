/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    let smaller = null, notSmaller = null;
    let smallerHead = null, notSmallerHead = null;
    let current = head;
    
    while(current !== null){
        if(current.val < x) {
            if(smallerHead === null){
                smallerHead = current;
                smaller = current;
            } else { 
                smaller.next = current;
                smaller = current;
            }
        } else {
            if(notSmallerHead === null){
                notSmallerHead = current;
                notSmaller = current;
            } else {
                notSmaller.next = current;
                notSmaller = current;
            }
        }
        current = current.next;
    }
    
    if(smaller !== null){
        smaller.next = notSmallerHead;
        if(notSmaller !== null)
            notSmaller.next = null;
        return smallerHead;
    }
    return head;
};