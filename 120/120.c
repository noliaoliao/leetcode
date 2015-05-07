//比较简单的动态规划题
//从倒数第二层处理就可以了
//算出该层到下一层的最小值
int minimumTotal(int **triangle, int numRows) {
    if(triangle == NULL || numRows == 0) return 0;
    for(int i = numRows-2; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            if(triangle[i+1][j] > triangle[i+1][j+1]){
                triangle[i][j] += triangle[i+1][j+1];
            }else{
                triangle[i][j] += triangle[i+1][j];
            }
        }
    }
    return triangle[0][0]; 
}