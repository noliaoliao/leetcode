#define MIN(a,b)    (((a) < (b)) ? (a) : (b))

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1)+1;
    int len2 = strlen(word2)+1;

    //分配距离矩阵
    int **distab = (int **)malloc(sizeof(int *)*len1);
    for(int i = 0; i < len1; i++){
        *(distab+i) = (int *)malloc(sizeof(int)*len2);
        memset(*(distab+i),0,sizeof(int)*len2);
    }

    //初始化矩阵第一行和第一列
    for(int i = 0; i < len1; i++){
        distab[i][0] = i;
    }
    for(int i = 0; i < len2; i++){
        distab[0][i] = i;
    }

    //计算剩余项
    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            int diff = (word1[i-1] == word2[j-1]) ? 0 : 1;
            int cost1 = distab[i-1][j-1]+diff;
            int cost2 = distab[i-1][j]+1;
            int cost3 = distab[i][j-1]+1;

            distab[i][j] = MIN(cost1,MIN(cost2,cost3));
        } 
    }

    return distab[len1-1][len2-1];
}