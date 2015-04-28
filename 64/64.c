int minPathSum(int **grid, int nRows, int nCols) {
    int i = 0;
    int j = 0;
    //这里分配的时候要注意,开始错误的写成了int
    //32位系统下sizeof(int)和sizeof(int*)大小是一样的
    //所以本机vs调试每错,oj报runtime error =。= 
    int **pathGrid = (int **)malloc(sizeof(int *)*(nRows+1));
    for(i = 0; i < nRows; i++){
        *(pathGrid+i) = (int *)malloc(sizeof(int)*(nCols+1));
        memset(*(pathGrid+i),0,sizeof(int)*(nCols+1));
    }
    pathGrid[0][0] = grid[0][0];
    for(i = 1; i < nRows; i++){
        pathGrid[i][0] = (pathGrid[i-1][0]+grid[i][0]);
    }
    for(i = 1; i < nCols; i++){
        pathGrid[0][i] = (pathGrid[0][i-1]+grid[0][i]);
    }
    for(i = 1; i < nRows; i++){
        for(j = 1; j < nCols; j++){
            pathGrid[i][j] = (pathGrid[i-1][j] < pathGrid[i][j-1]) ? (pathGrid[i-1][j]+grid[i][j]) : (pathGrid[i][j-1]+grid[i][j]);
        }
    }

    return pathGrid[nRows-1][nCols-1];
}