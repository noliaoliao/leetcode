/**
    DP
    从右下角遍历到左下角
*/

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    if(dungeon == NULL || dungeonColSize <= 0 || dungeonRowSize <= 0) return 0;
    
    //int nMinimumHP = 0;
    int **hpTab = (int **)malloc(sizeof(int *)*dungeonRowSize);
    for(int i = 0; i < dungeonRowSize; i++){
        *(hpTab+i) = (int *)malloc(sizeof(int)*dungeonColSize);
        memset(*(hpTab+i),0,sizeof(int)*dungeonColSize);
    }

    if(dungeon[dungeonRowSize-1][dungeonColSize-1] < 0){
        hpTab[dungeonRowSize-1][dungeonColSize-1] = 1-dungeon[dungeonRowSize-1][dungeonColSize-1];
    }else{
        hpTab[dungeonRowSize-1][dungeonColSize-1] = 1;
    }

    //初始化最后一列
    for(int i = dungeonRowSize-2; i >= 0; i--){
        int nMinCurrHP = dungeon[i][dungeonColSize-1] - hpTab[i+1][dungeonColSize-1];
        if(nMinCurrHP >= 0){
            hpTab[i][dungeonColSize-1] = 1;
        }else{
            hpTab[i][dungeonColSize-1] = 0-nMinCurrHP;
        }
    }
    //初始化最后一行
    for(int i = dungeonColSize-2; i >= 0; i--){
        int nMinCurrHP = dungeon[dungeonRowSize-1][i] - hpTab[dungeonRowSize-1][i+1];
        if(nMinCurrHP >= 0){
            hpTab[dungeonRowSize-1][i] = 1;
        }else{
            hpTab[dungeonRowSize-1][i] = 0 - nMinCurrHP;
        }
    }

    //依次生成剩余的项
    for(int i = dungeonRowSize-2; i >= 0; i--){
        for(int j = dungeonColSize-2; j >= 0; j--){
            int nMinNextHP = hpTab[i+1][j] < hpTab[i][j+1] ? hpTab[i+1][j] : hpTab[i][j+1];
            int nMinCurrHP = dungeon[i][j] - nMinNextHP;
            if(nMinCurrHP >= 0){
                hpTab[i][j] = 1;
            }else{
                hpTab[i][j] = 0 - nMinCurrHP;
            }
        }
    }

    return hpTab[0][0];
}