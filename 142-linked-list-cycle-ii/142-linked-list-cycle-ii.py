# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head 
        cycleFound = False
        
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                cycleFound = True
                break
        
        if not cycleFound:
            return None
        
        slow = head
        while slow is not fast:
            slow = slow.next
            fast = fast.next
        
        return slow