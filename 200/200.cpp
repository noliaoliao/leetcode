struct Position{
    int x;
    int y;
    Position() : x(0),y(0) {}
    Position(int i, int j) : x(i),y(j) {}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        if(grid.size() <= 0) return 0;
        int gridRowSize = grid.size();
        int gridColSize = grid[0].size();
        //if(gridRowSize <= 2 || gridColSize <= 2) return ;

        //用htab表示'1'是否被访问过
        int **htab = (int **)malloc(sizeof(int *)*gridRowSize);
        for(int i = 0; i < gridRowSize; i++){
            *(htab+i) = (int *)malloc(sizeof(int)*gridColSize);
            memset(*(htab+i),0,sizeof(int)*gridColSize);
        }

        int nIslandNum = 0;
        //先找一遍四周,这些1必定是一个岛屿的一点
        for(int i = 0; i < gridColSize; i++){
            if(grid[0][i] == '1' && htab[0][i] == 0){
                nIslandNum++;
                htab[0][i] = 1;
                findOne(grid,gridRowSize,gridColSize,htab,0,i);
            }
            if(grid[gridRowSize-1][i] == '1' && htab[gridRowSize-1][i] == 0){
                nIslandNum++;
                htab[gridRowSize-1][i] = 1;
                findOne(grid,gridRowSize,gridColSize,htab,gridRowSize-1,i);
            }
        }
        for(int i = 0; i < gridRowSize; i++){
            if(grid[i][0] == '1' && htab[i][0] == 0){
                nIslandNum++;
                htab[i][0] = 1;
                findOne(grid,gridRowSize,gridColSize,htab,i,0);
            }
            if(grid[i][gridColSize-1] == '1' && htab[i][gridColSize-1] == 0){
                nIslandNum++;
                htab[i][gridColSize-1] = 1;
                findOne(grid,gridRowSize,gridColSize,htab,i,gridColSize-1);
            }
        }

        //遍历grid,以未访问过的1为起点进行广度优先遍历
        for(int i = 1; i < gridRowSize-1; i++){
            for(int j = 1; j < gridColSize-1; j++){
                if(grid[i][j] == '1' && htab[i][j] == 0){
                    nIslandNum++;
                    htab[i][j] = 1;
                    findOne(grid,gridRowSize,gridColSize,htab,i,j);
                }
            }
        }

        return nIslandNum;
    }

    //BFS找到相邻的'1',将其标记为1,相当于岛屿扩展的过程
    void findOne(vector<vector<char>>& board, int nRows, int nCols, int **htab, int row, int col){
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        queue<Position> q;
        Position start(row,col);    
        q.push(start);
        while(q.empty() == false){
            Position currPos = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int newRow = currPos.x+x[i];
                int newCol = currPos.y+y[i];
                if(newRow < nRows && newRow >= 0 && newCol < nCols && newCol >= 0 \
                && board[newRow][newCol] == '1' && htab[newRow][newCol] == 0){
                    htab[newRow][newCol] = 1;
                    Position newPos(newRow,newCol);
                    q.push(newPos);
                }
            }
        }
    }
};