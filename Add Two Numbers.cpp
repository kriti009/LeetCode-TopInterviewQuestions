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
    int carry=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        cout<<carry<<" ";
        // cout<<l1->val<<" "<<l2->val<<endl;
        if(l1==NULL && l2==NULL)
            return (carry==0)?NULL:new ListNode(carry);
        if(l1==NULL){
            if(carry==0)return l2;
            else{
                int x = l2->val+carry;
                l2->val = x%10;
                carry=x/10;
                l2->next =  addTwoNumbers(l1,l2->next);
                return l2;
            }
        }
        if(l2==NULL){
            if(carry==0)return l1;
            else{
                int x = l1->val+carry;
                l1->val = x%10;
                carry=x/10;
                l1->next =  addTwoNumbers(l1->next,l2);
                return l1;
            }
        }
            // return l1;
        ListNode* l = new ListNode((l1->val+l2->val+carry)%10);
        carry=(l1->val + l2->val + carry)/10;
        l->next = addTwoNumbers(l1->next,l2->next);
        return l;
    }
};
