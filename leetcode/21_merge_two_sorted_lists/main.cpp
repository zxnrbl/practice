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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = nullptr;

        if(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                root = l1;
                l1 = l1->next;
            }
            else {
                root = l2;
                l2 = l2->next;
            }
        }
        else if(l1 != nullptr) {
            root = l1;
            l1 = l1->next;
        }
        else if(l2 != nullptr) {
            root = l2;
            l2 = l2->next;
        }

        ListNode* current = root;

        while(l1 != nullptr || l2 != nullptr) {
            if(l1 == nullptr) {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
            else if(l2 == nullptr) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else if(l1->val < l2->val) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }

        return root;
    }
};
