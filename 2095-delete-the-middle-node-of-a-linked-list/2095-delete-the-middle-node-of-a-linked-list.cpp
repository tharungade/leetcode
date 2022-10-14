/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int giveLen(ListNode* head)
    {
        if(head == NULL)
            return 0;
        
        return 1 + giveLen(head->next);
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;
        
        int len = giveLen(head);
        int mid = len/2;
        ListNode *temp = head;
        for(int i = 1; i < mid; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        
        return head;
    }
};