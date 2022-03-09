# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None:
            return head
        
        dummy = ListNode(None, None)
        lastNode = dummy
        
        first = second = head
        while first is not None:
            while second is not None and first.val == second.val:
                second = second.next
            if first.next is second:
                lastNode.next = first
                lastNode = lastNode.next
                lastNode.next = None
            first = second
        
        return dummy.next
        
        