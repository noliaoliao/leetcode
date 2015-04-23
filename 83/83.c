/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *pre = head;
    struct ListNode *cur = NULL;
    if(pre){
        cur = pre->next;
    }
    while(cur != NULL)
    {
        if(pre->val == cur->val)
        {
            pre->next = cur->next;
            //free(cur);
            cur = pre->next;
        }
        else{
            pre = pre->next;
            cur = cur->next;
        }
    }
    return head;
}