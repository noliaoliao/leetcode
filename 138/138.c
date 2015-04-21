/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */

//���������ÿһ���ڵ�,ֱ�Ӽ���ԭ����ĺ���
//random��ʱ������,��Ϊ����ڵ㲢û�и������
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

//�����ƵĽڵ�randomָ�븳ֵ
void setRandom(struct RandomListNode *head){
    struct RandomListNode *pCur = head;
    struct RandomListNode *pClone = NULL;
    while(pCur != NULL){
        pClone = pCur->next;
        //��Ҫ�жϲ�Ϊ�յ����
        if(pCur->random != NULL){
            pClone->random = pCur->random->next;
        }
        pCur = pClone->next;
    }
}

//��������
struct RandomListNode *getCloneList(struct RandomListNode *head){
    struct RandomListNode *pCur = head;
    struct RandomListNode *pCloneHead = NULL;
    struct RandomListNode *pClonePre = NULL;
    //������ͷ��
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