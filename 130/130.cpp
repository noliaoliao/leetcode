struct Position{
    int x;
    int y;
    Position() : x(0),y(0) {}
    Position(int i, int j) : x(i),y(j) {}
};

class Solution {
public:
    void findBadZero(vector<vector<char>>& board, int nRows, int nCols, int **htab, int row, int col){
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
                if(newRow < nRows && newRow >= 0 && newCol < nCols && newCol >= 0 && board[newRow][newCol] == 'O' && htab[newRow][newCol] == 0){
                    htab[newRow][newCol] = 1;
                    Position newPos(newRow,newCol);
                    q.push(newPos);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.size() <= 0) return;
        int boardRowSize = board.size();
        int boardColSize = board[0].size();
        if(boardRowSize <= 2 || boardColSize <= 2) return ;

        //用htab代表0是否没有被围绕
        int **htab = (int **)malloc(sizeof(int *)*boardRowSize);
        for(int i = 0; i < boardRowSize; i++){
            *(htab+i) = (int *)malloc(sizeof(int)*boardColSize);
            memset(*(htab+i),0,sizeof(int)*boardColSize);
        }

        //从四周的O出发,进行广度优先遍历,标记连通的O
        //这些O不会被X包围
        for(int i = 0; i < boardColSize; i++){
            if(board[0][i] == 'O' && htab[0][i] == 0){
                htab[0][i] = 1;
                findBadZero(board,boardRowSize,boardColSize,htab,0,i);
            }
            if(board[boardRowSize-1][i] == 'O' && htab[boardRowSize-1][i] == 0){
                htab[boardRowSize-1][i] = 1;
                findBadZero(board,boardRowSize,boardColSize,htab,boardRowSize-1,i);
            }
        }
        for(int i = 0; i < boardRowSize; i++){
            if(board[i][0] == 'O' && htab[i][0] == 0){
                htab[i][0] = 1;
                findBadZero(board,boardRowSize,boardColSize,htab,i,0);
            }
            if(board[i][boardColSize-1] == 'O' && htab[i][boardColSize-1] == 0){
                htab[i][boardColSize-1] = 1;
                findBadZero(board,boardRowSize,boardColSize,htab,i,boardColSize-1);
            }
        }
        
        //将被包围的O该为X
        for(int i = 0; i < boardRowSize; i++){
            for(int j = 0; j < boardColSize; j++){
                if(board[i][j] == 'O' && htab[i][j] == 0) board[i][j] = 'X';
            }
        }

        return ;
    }
};