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
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;
        return dummynode->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* midpoint = mid(head);
        ListNode* lefthead = head;
        ListNode* righthead = midpoint->next;
        midpoint->next = nullptr;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return mergeList(lefthead, righthead);
    }
};
