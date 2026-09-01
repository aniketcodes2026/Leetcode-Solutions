class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* answer = new ListNode(0);
        ListNode* current = answer;

        int carry = 0;

        while (l1 != NULL || l2 != NULL) {

            int sum = carry;

            if (l1 != NULL) {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            if (sum >= 10) {
                carry = 1;
                sum = sum - 10;
            }
            else {
                carry = 0;
            }

            current->next = new ListNode(sum);
            current = current->next;
        }

        if (carry == 1) {
            current->next = new ListNode(1);
        }
        return answer->next;
    }
};
