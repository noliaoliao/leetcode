int uniquePathsWithObstacles(int **obstacleGrid, int m, int n){
    if(obstacleGrid[0][0] == 1) return 0;
    int **uniPaths = (int **)malloc(sizeof(int *)*m);
    for(int i = 0; i < m; i++){
        *(uniPaths+i) = (int *)malloc(sizeof(int)*n);
    }
    uniPaths[0][0] = 1;
    for(int i = 1; i < m; i++){
        uniPaths[i][0] = obstacleGrid[i][0] == 0 ? uniPaths[i-1][0] : 0;
    }
    for(int i = 1; i < n; i++){
        uniPaths[0][i] = obstacleGrid[0][i] == 0 ? uniPaths[0][i-1] : 0;
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                uniPaths[i][j] = 0;
            }else{
                uniPaths[i][j] = uniPaths[i-1][j] + uniPaths[i][j-1];
            }
        }
    }

    return uniPaths[m-1][n-1];
}