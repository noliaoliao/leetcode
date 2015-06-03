#define MIN(A,B) ((A)<(B)?(A):(B))

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nRows = matrix.size();
        if(nRows <= 0) return 0;
        int nCols = matrix[0].size();

        int maxAreaEdge = 0;
        vector<vector<int>> maxtab(nRows+1,vector<int>(nCols+1,0));
        for(int i = 1; i < nRows+1; i++){
            for(int j = 1; j < nCols+1; j++){
                //maxtab[i][j]代表以i,j为右小角的最大正方形的边
                //状态转移方程
                //maxtab[i][j] = 0 (matrix[i][j] = 0)
                //maxtab[i][j] = min(maxtab[i-1][j-1],matrix[i-1][j],matrix[i][j-1])
                //即另外3个点的最小值
                if(matrix[i-1][j-1] == '0'){
                    maxtab[i][j] = 0;
                }else{
                    maxtab[i][j] = MIN(maxtab[i-1][j-1],MIN(maxtab[i-1][j],maxtab[i][j-1]))+1;
                    if(maxtab[i][j] > maxAreaEdge) maxAreaEdge = maxtab[i][j];
                }
            }
        }
        
        return maxAreaEdge*maxAreaEdge;
    }
};