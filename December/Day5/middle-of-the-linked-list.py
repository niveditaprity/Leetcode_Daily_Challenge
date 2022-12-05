class Solution:
    def middle(self, head):
        slow, fast = head, head.next

        while (fast.next and fast.next.next):
            slow = slow.next
            fast = fast.next.next
        
        return slow

    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return head
        middle = self.middle(head)
        return middle.next