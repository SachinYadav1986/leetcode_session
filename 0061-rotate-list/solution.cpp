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
    int callength(ListNode* head){
        ListNode*temp=head;
        int countlen=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            countlen++;
        }
    return countlen;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int length=callength(head);
        if(k%length==0) return head;
        int NoOfrotation=k%length;
        int kthNodeBeforeHead=length-NoOfrotation;

        int i=1;
        ListNode*kthNode=nullptr;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            if(i==kthNodeBeforeHead){
                kthNode=temp;
            }
            temp=temp->next;
            i++;
        }
        temp->next=head;
        head=kthNode->next;
        kthNode->next=nullptr;
    return head;
    }
};
