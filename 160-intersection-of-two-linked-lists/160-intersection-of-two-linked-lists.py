# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        n, m = 0, 0
        
        node = headA
        while node is not None:
            n += 1
            node = node.next
        
        node = headB
        while node is not None:
            m += 1
            node = node.next
            
        if n < m:
            headA, headB = headB, headA
            n, m = m, n
        
        extra = n - m
        nodeA = headA
        nodeB = headB
        
        while extra > 0:
            nodeA = nodeA.next
            extra -= 1
        
        while nodeA and nodeB:
            if nodeA is nodeB:
                return nodeA
            nodeA = nodeA.next
            nodeB = nodeB.next
        
        return None