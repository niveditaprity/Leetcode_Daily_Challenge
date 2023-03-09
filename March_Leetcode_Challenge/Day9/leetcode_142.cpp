class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     unordered_map<ListNode*,int>mp;
     ListNode*temp = head;
     while(temp!=NULL) {
        if(mp[temp])
        {
            return temp;
        }
        mp[temp]++;
        temp = temp->next;
     } 
     return NULL;
    }
};



// slow and fast pointer

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode*fast=head;
     ListNode*slow=head;
        bool flag=0;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
              fast=head;
            while(fast!=slow)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        }
        return NULL;   
    }
};
