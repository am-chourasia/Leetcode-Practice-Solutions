# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        prevMini = prevNode = None
        mini = node = head
        
        while node != None:
            if node.val < mini.val:
                mini, prevMini = node, prevNode
            prevNode, node = node, node.next
        
        if prevMini == None:
            mini.next = self.insertionSortList(head.next)
        else:
            prevMini.next = mini.next
            mini.next = self.insertionSortList(head)
        return mini