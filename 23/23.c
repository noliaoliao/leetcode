/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct heapNode{
    int nCur;
    int nVal;
};

struct minHeap{
    int nMaxLen;
    int nDataLen;
    struct heapNode *pHeapBuf;
};

void swapData(struct heapNode *a, struct heapNode *b){
    struct heapNode tmp = {0};
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//初始化一个堆
void initMinHeap(struct minHeap *pHeap, int nSize){
    //pHeap = (struct minHeap *)malloc(sizeof(struct minHeap));
    pHeap->nDataLen = 0;
    pHeap->nMaxLen = nSize;
    pHeap->pHeapBuf = (struct heapNode *)malloc(sizeof(struct heapNode)*nSize);
    memset(pHeap->pHeapBuf,0,sizeof(struct heapNode)*nSize);
}

//push一个元素
bool pushHeap(struct minHeap *pHeap, struct heapNode data){
    //struct heapNode tmp;
    if(pHeap->nDataLen >= pHeap->nMaxLen){
        return false;
    }
    //新压入的数组总在最后
    pHeap->pHeapBuf[pHeap->nDataLen] = data;
    pHeap->nDataLen++;
    //调整堆的顺序
    //如果子节点比父节点小，则交换两者的值
    //依次往上和父节点比较，上升操作
    int nIndex = pHeap->nDataLen - 1;
    while(pHeap->pHeapBuf[nIndex].nVal < pHeap->pHeapBuf[(nIndex-1)/2].nVal)
    {
        swapData(&pHeap->pHeapBuf[nIndex],&pHeap->pHeapBuf[(nIndex-1)/2]);
        nIndex = (nIndex - 1) / 2;
    }
    return true;
}

struct heapNode popHeap(struct minHeap *pHeap){
    int nIndex = 0;
    int nlChild = 0;
    int nrChild = 0;
    struct heapNode ret = {0};

    if(pHeap->nDataLen == 0) return ret;     //堆为空
    ret = pHeap->pHeapBuf[0];                  //出堆的总是第一个元素
    pHeap->nDataLen--;

    //将最后一个元素放到最前，执行下降操作
    swapData(&pHeap->pHeapBuf[0],&pHeap->pHeapBuf[pHeap->nDataLen]);
    while(nIndex < pHeap->nDataLen)
    {
        nlChild = nIndex * 2 + 1;
        nrChild = nIndex * 2 + 2;

        //左右孩子节点同时存在
        if(nlChild < pHeap->nDataLen && nrChild < pHeap->nDataLen)
        {
            //如果最后一个元素比左右孩子中的一个大,则和较小的交换
            if(pHeap->pHeapBuf[nIndex].nVal < pHeap->pHeapBuf[nlChild].nVal &&
                pHeap->pHeapBuf[nIndex].nVal < pHeap->pHeapBuf[nrChild].nVal) break;
            if(pHeap->pHeapBuf[nlChild].nVal < pHeap->pHeapBuf[nrChild].nVal)
            {
                swapData(&pHeap->pHeapBuf[nIndex],&pHeap->pHeapBuf[nlChild]);
                nIndex = nlChild;
            }
            else
            {
                swapData(&pHeap->pHeapBuf[nIndex],&pHeap->pHeapBuf[nrChild]);
                nIndex = nrChild;
            }
        }
        //只有左孩子,且比左孩子大
        else if(nlChild < pHeap->nDataLen && pHeap->pHeapBuf[nIndex].nVal > pHeap->pHeapBuf[nlChild].nVal)
        {
            swapData(&pHeap->pHeapBuf[nIndex],&pHeap->pHeapBuf[nlChild]);
            nIndex = nlChild;
        }
        else
        {
            break;
        }
    }

    return ret;
}

bool isEmpty(struct minHeap heap){
    return heap.nDataLen == 0;
}

struct ListNode *mergeKLists(struct ListNode *lists[], int k) {
    struct ListNode *pHead = NULL;
    struct ListNode *pPre  = NULL;
    struct ListNode *pCur = NULL;
    struct minHeap  heapMin = {0};
    struct heapNode curNode = {0};
    struct heapNode getNode = {0};
    int i = 0;
    if(k == 0) return NULL;
    if(k == 1) return lists[0];

    //初始化k大小的最小堆,将每个链表的头结点压入到堆中
    initMinHeap(&heapMin,k);
    for(i = 0; i < k; i++){
        if(lists[i] != NULL){
            curNode.nCur = i;
            curNode.nVal = lists[i]->val;
            pushHeap(&heapMin,curNode);
            lists[i] = lists[i]->next;
        }
    }
    //依次取出
    while(isEmpty(heapMin) == false){
        getNode = popHeap(&heapMin);
        if(pHead == NULL){
            pHead = (struct ListNode *)malloc(sizeof(struct ListNode));
            pHead->next = NULL;
            pHead->val = getNode.nVal;
            pPre = pHead;
        }else{
            pPre->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            pPre->next->val = getNode.nVal;
            pPre = pPre->next;
            pPre->next = NULL;
        }
        if(lists[getNode.nCur] != NULL){
            curNode.nCur = getNode.nCur;
            curNode.nVal = lists[getNode.nCur]->val;
            pushHeap(&heapMin,curNode);
            lists[getNode.nCur] = lists[getNode.nCur]->next;
        }
    }

    return pHead;
}
