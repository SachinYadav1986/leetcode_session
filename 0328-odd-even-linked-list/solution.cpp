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
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *oddnode=head;
        ListNode *oddhead=oddnode;
        ListNode *evennode=head->next;
        ListNode *evenhead=evennode;
        while(evennode!=nullptr && evennode->next!=nullptr){
            oddnode->next=oddnode->next->next;
            evennode->next=evennode->next->next;
            oddnode=oddnode->next;
            evennode=evennode->next;
        }
        oddnode->next=evenhead;
        return oddhead;
    }
};
