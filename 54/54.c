/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void printOnce(int **matrix, int nRows, int nCols, int start, int *pRetArray, int *nCur){
    int endX = nCols - start - 1;
    int endY = nRows - start - 1;

    //左到右
    for(int i = start; i <= endX; i++){
        //printf("%d ",matrix[start][i]);
        pRetArray[(*nCur)++] = matrix[start][i];
    }
    //右到下
    if(start < endY){
        for(int i = start+1; i <= endY; i++){
            //printf("%d ",matrix[i][endX]);
            pRetArray[(*nCur)++] = matrix[i][endX];
        }
    }
    //右到左
    if(start < endX && start < endY){
        for(int i = endX-1; i >= start; i--){
            //printf("%d ",matrix[endY][i]);
            pRetArray[(*nCur)++] = matrix[endY][i];
        }
    }
    //下到上
    if(start < endX && start < endY-1){
        for(int i = endY-1; i >= start+1; i--){
            //printf("%d ",matrix[i][start]);
            pRetArray[(*nCur)++] = matrix[i][start];
        }
    }
}

int *spiralOrder(int **matrix, int numRows, int numColumns) {
    int start  = 0;
    int *ret = (int *)malloc(sizeof(int)*(numRows*numColumns+1));
    int cur = 0;
    while(numRows > start*2 && numColumns > start*2){
        printOnce(matrix,numRows,numColumns,start,ret,&cur);
        start++;
    }

    return ret;
}