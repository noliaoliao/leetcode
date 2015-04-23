/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pRetHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *pRetCur = pRetHead;
    struct ListNode *pWalk = head;
    //pRetHead->next = NULL;

    while(pWalk != NULL){
        if(pWalk->val != val){
            pRetCur->next = pWalk;
            pRetCur = pRetCur->next;
        }
        pWalk = pWalk->next;
    }
    pRetCur->next = NULL;
    return pRetHead->next;
}