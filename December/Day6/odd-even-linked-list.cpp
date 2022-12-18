class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // If there is no node inside the list, return NULL.
        if(head == NULL) {
            return head;
        }

        // Keep odd pointer on the 1st node and even pointer on the 2nd node.
        ListNode *odd = head, *even = head->next;
        // 2nd node will be the 1st even node in the list. Take this node as head of even list.
        ListNode* evenHead = head->next;

        // At every iteration, connect odd node to next odd node and even node to next even node.
        while(even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;

            // Update odd and even pointer for next iteration.
            odd = odd->next;
            even = even->next;
        }

        // Connect the odd nodes linked list to even nodes linked list.
        odd->next = evenHead;
        return head;
    }
};