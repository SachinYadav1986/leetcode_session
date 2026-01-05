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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummynode=new ListNode(-1);
        ListNode* temp=dummynode;
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        while(t2!=nullptr && t1!=nullptr){

            int value=0;
            if(t1) value+=t1->val;
            if(t2) value+=t2->val;
            value=value+carry;
            ListNode* newNode=new ListNode(value%10);
            carry=value/10;
            temp->next=newNode;
            temp=temp->next;
            t1=t1->next;
            t2=t2->next;
            if(t1==nullptr){
                while(t2!=nullptr){
                    value=0;
                    value=t2->val+carry;
                    ListNode* newNode1=new ListNode(value%10);
                    temp->next=newNode1;
                    temp=temp->next;
                    carry=value/10;
                    t2=t2->next;
                }
            }
            if(t2==nullptr){
                while(t1!=nullptr){
                    value=0;
                    value=t1->val+carry;
                    ListNode* newNode1=new ListNode(value%10);
                    temp->next=newNode1;
                    temp=temp->next;
                    carry=value/10;
                    t1=t1->next;
                }
            }
        
    }
    if(carry==1){
        ListNode* newNode=new ListNode(1);
        temp->next=newNode;
        temp=temp->next;
    }
    return dummynode->next;
    }
};
