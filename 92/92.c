/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    struct ListNode * pM = NULL;
    struct ListNode * pPre = NULL;
    struct ListNode * pCur = head;
    struct ListNode * pNext = NULL;
    int i = 0;
    if(head == NULL) return NULL;
    if(m == n) return head; 
    while(i < m - 1){
        pM = pCur;         //记录要转换那部分链表的前一个节点
        pCur = pCur->next;
        i++;
    }
    //开始逆转m-n部分的链表
    pPre = pM;
    while(i < n && pCur != NULL){
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
        i++;
    }
    if(pM == NULL){
        head->next = pNext;
        head = pPre;
    }else{
        pM->next->next = pCur;
        pM->next = pPre;
    }
    return head;
    
}