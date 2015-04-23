struct ListNode *reverseBetween(struct ListNode *head, struct ListNode *pM, int m, int n) {
    //struct ListNode * pM = NULL;
    struct ListNode * pPre = NULL;
    struct ListNode * pCur = head;
    struct ListNode * pNext = NULL;
    int i = 0;
    if(head == NULL) return NULL;
    if(m == n) return head; 
    /*
    找到要逆转的部分,这部分通过pM参数传进来,
    同时逆转完之后这个值为链表尾节点
    while(i < m - 1){
        pM = pCur;         //记录要转换那部分链表的前一个节点
        pCur = pCur->next;
        i++;    
    }*/
    
    //开始逆转m-n部分的链表
    pPre = pM;
    pCur = pM == NULL ? head : pM->next;
    while(i < n && pCur != NULL){
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
        i++;
    }
    //保存pM的值
    pM = pCur == NULL ? NULL : pCur->next;
    if(pM == NULL){
        head->next = pNext;
        head = pPre;
    }else{
        pM->next->next = pCur;
        pM->next = pPre;
    }
    
    return head;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    struct ListNode *pTmp  = NULL;
    struct ListNode *pCur  = head;
    struct ListNode *pPre  = NULL;
    int i = 1;
    int nLen = 0;
    if(head == NULL || head->next == NULL || k <= 1) return head;
    //先求一个链表的长度
    while(pCur != NULL){
        nLen++;
        pCur = pCur->next;
    }
    //依次逆转
    while(i*k <= nLen){
        head = reverseBetween(head,pTmp,(i-1)*k+1,i*k);
        i++;
    }
    
    return head;
}