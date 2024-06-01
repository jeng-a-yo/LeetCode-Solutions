/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Initialize dummy node to simplify code and current node pointer
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;
    
    int carry = 0;
    
    // Loop until both lists are fully traversed or there is a carry left
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        current->next = newNode;
        current = current->next;
    }
    
    return dummy.next;
}
