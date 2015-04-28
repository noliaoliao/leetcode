int uniquePaths(int m, int n) {
    int i = 0;
    int j = 0;
    if(m < 1 || n < 1) return 0;
    if(m == 1 || n == 1) return 1;
    int **pArray = (int **)malloc(sizeof(int *)*m);
    for(i = 0; i < m; i++){
        *(pArray+i) = (int *)malloc(sizeof(int)*n);
    }
    pArray[0][0] = 0;
    for(i = 1; i < m; i++){
        pArray[i][0] = 1;
    }
    for(i = 1; i < n; i++){
        pArray[0][i] = 1;
    }
    for(i = 1; i < m; i++){
        for(j = 1; j < n; j++){
            pArray[i][j] = pArray[i-1][j] + pArray[i][j-1];
        }
    }

    return pArray[m-1][n-1];
}