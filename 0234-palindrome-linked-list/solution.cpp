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
        ListNode *reversehalf(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *newhead=reversehalf(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        if(fast==nullptr && fast->next==nullptr) return true;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            
            slow=slow->next;
            fast=fast->next->next;
            
        }
        ListNode *secondhead=reversehalf(slow->next);
        ListNode *firsthead=head;
        while(firsthead!=nullptr && secondhead!=nullptr){
            if(firsthead->val!=secondhead->val) return false;
            firsthead=firsthead->next;
            secondhead=secondhead->next;
        }
        return true;
    }
};
