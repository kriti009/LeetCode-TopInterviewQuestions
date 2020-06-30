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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL || head->next->next==NULL)
            return head;
        ListNode* even=new ListNode(0),*p=head,*q,*temp;
        q=even,temp=p;
        while(p!=nullptr){
            even->next = p->next;
            even = even->next;
            if(p->next!=NULL)
                p->next=p->next->next;
            temp=p;
            p = p->next;
        }
        temp->next = q->next;
        return head;
    }
};
