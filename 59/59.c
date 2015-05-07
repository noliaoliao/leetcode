/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void printOnce(int **matrix, int nRows, int nCols, int start, int *nCur){
    int endX = nCols - start - 1;
    int endY = nRows - start - 1;

    //左到右
    for(int i = start; i <= endX; i++){
        //printf("%d ",matrix[start][i]);
        matrix[start][i] = (*nCur)++;
    }
    //右到下
    if(start < endY){
        for(int i = start+1; i <= endY; i++){
           matrix[i][endX] = (*nCur)++;
        }
    }
    //右到左
    if(start < endX && start < endY){
        for(int i = endX-1; i >= start; i--){
            matrix[endY][i] = (*nCur)++;
        }
    }
    //下到上
    if(start < endX && start < endY-1){
        for(int i = endY-1; i >= start+1; i--){
            matrix[i][start] = (*nCur)++;
        }
    }
}

int** generateMatrix(int n) {
    int **matrix = (int **)malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        *(matrix+i) = (int *)malloc(sizeof(int)*n);
    }
    int start = 0;
    int cur = 1;
    while(n > start*2 && n > start*2){
        printOnce(matrix,n,n,start,&cur);
        start++;
    }
    return matrix;
}