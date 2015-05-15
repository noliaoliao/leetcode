void findNext(char **board, int boardRowSize, int boardColSize, char *word, int x, int y,int nIndex, int *htab, int *bFind){
    //if(nIndex == strlen(word)) return;
    int direct[] = {0,-1,0,1,-1,0,1,0};
    //从4个方向搜索
    for(int i = 0; i < 4; i++){
        int nRow = x+direct[i*2];
        int nCol = y+direct[i*2+1];
        //判断合法性
        if(nRow >= 0 && nRow < boardRowSize && nCol >= 0 && nCol < boardColSize && htab[nRow*boardColSize+nCol] == 0){
            //如果匹配
            if(board[nRow][nCol] == word[nIndex]){
                if(nIndex == strlen(word)-1){
                    *bFind = 1;
                    return; 
                }else if(nIndex < strlen(word)-1  && *bFind == 0){
                    //没有到单词的长度,并且没有找到,则继续搜索
                    htab[nRow*boardColSize+nCol] =  1;
                    findNext(board,boardRowSize,boardColSize,word,nRow,nCol,nIndex+1,htab,bFind);
                    //恢复标记数组
                    htab[nRow*boardColSize+nCol] =  0;
                }
            }
        }
    }
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if(word == NULL || board == NULL || boardRowSize == 0 || boardColSize == 0) return false;
    int *htab = (int *)malloc(sizeof(int)*(boardRowSize*boardColSize+1));
    memset(htab,0,sizeof(int)*(boardRowSize*boardColSize+1));
    int bRet = 0;
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            if(board[i][j] == word[0]){
                if(strlen(word) == 1) return true;
                htab[i*boardColSize+j] = 1;
                findNext(board,boardRowSize,boardColSize,word,i,j,1,htab,&bRet);
                htab[i*boardColSize+j] = 0;
            }
        }
    }
    return bRet == 1 ? true : false;
}