/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *pPre = NULL;
    struct ListNode *pHead = NULL;
    struct ListNode *pCur = NULL;
    struct ListNode *pWalk = NULL;
    int nCount = 0;
    int nCurVal = 0;
    if(head == NULL || head->next == NULL) return head;
    nCurVal = head->val;
    pCur = head;
    while(pCur != NULL){
        //跳过中间数值相同的
        //pWalk = pCur;
        while(pCur != NULL && nCurVal == pCur->val){
            nCount++;
            pWalk = pCur;
            pCur = pCur->next;
        }
        if(nCount == 1){
            if(pPre == NULL){
                pHead = pWalk;
                pPre = pHead;
                pPre->next = NULL;
            }else{
                pPre->next = pWalk;
                pPre = pPre->next;
                pPre->next = NULL;
            }
        }
        if(pCur){
            nCount = 0;
            nCurVal = pCur->val;
        }
    }

    return pHead;
}