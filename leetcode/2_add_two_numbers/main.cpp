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
        int carry = 0;
        ListNode* head = new ListNode(carryAdd(l1->val, l2->val, carry));
        ListNode* tail = head;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 != nullptr || l2 != nullptr || carry == 1) {
            ListNode* node = new ListNode();
            tail->next = node;
            tail = node;

            if(l1 && l2) {
                node->val = carryAdd(l1->val, l2->val, carry);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 && !l2) {
                node->val = carryAdd(l1->val, 0, carry);
                l1 = l1->next;
            }
            else if(!l1 && l2) {
                node->val = carryAdd(0, l2->val, carry);
                l2 = l2->next;
            }
            else if(carry == 1) {
                node->val = carryAdd(0, 0, carry);
            }
        }

        return head;
    }

private:
    int carryAdd(int val1, int val2, int& carry) {
        const int result = (val1 + val2 + carry) % 10;
        carry = (val1 + val2 + carry) > 9 ? 1:0;
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
