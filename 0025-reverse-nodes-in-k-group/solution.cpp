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
    ListNode* findKthNode(ListNode* temp,int k){
        int i=1;
        ListNode*temp1=temp;
        while(temp1!=nullptr && i<k){
            temp1=temp1->next;
            i++;
        }
        return temp1;
    }
    ListNode* reversegroup(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *newhead=reversegroup(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*newNode;
        ListNode*prev=nullptr;
        while(temp!=nullptr){
            ListNode*kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                
                break;
            }
            
            newNode=kthNode->next;
            kthNode->next=nullptr;
            ListNode* newhead=reversegroup(temp);
            if(prev==nullptr){
                head=newhead;
            }else{
                prev->next=newhead;
            }
            temp->next=newNode;
            prev=temp;
            temp=newNode;   
        }
    return head;
    }
};
