/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */

//复制链表的每一个节点,直接加在原链表的后面
//random暂时不处理,因为链表节点并没有复制完毕
void cloneNodes(struct RandomListNode *head) {
    struct RandomListNode *pCur = head;
    struct RandomListNode *pClone = NULL;
    while(pCur != NULL){
        pClone = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        pClone->label = pCur->label;
        pClone->next = pCur->next;
        pClone->random = NULL;
        pCur->next = pClone;
        pCur = pClone->next;
    }
}

//给复制的节点random指针赋值
void setRandom(struct RandomListNode *head){
    struct RandomListNode *pCur = head;
    struct RandomListNode *pClone = NULL;
    while(pCur != NULL){
        pClone = pCur->next;
        //需要判断不为空的情况
        if(pCur->random != NULL){
            pClone->random = pCur->random->next;
        }
        pCur = pClone->next;
    }
}

//分离链表
struct RandomListNode *getCloneList(struct RandomListNode *head){
    struct RandomListNode *pCur = head;
    struct RandomListNode *pCloneHead = NULL;
    struct RandomListNode *pClonePre = NULL;
    //处理下头部
    if(pCur != NULL){
        pCloneHead = pCur->next;
        pClonePre = pCloneHead;
        pCur->next = pCloneHead->next;
        pCur = pCur->next;
    }
    while(pCur != NULL){
        pClonePre->next = pCur->next;
        pClonePre = pClonePre->next;
        pCur->next = pClonePre->next;
        pCur = pCur->next;
        pClonePre->next = NULL;
    }
    
    return pCloneHead;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    cloneNodes(head);
    setRandom(head);
    return getCloneList(head);
}