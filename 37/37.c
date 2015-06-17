/*Sudoku Solver*/

void sudokuSolution(char ** result, char** board, int boardSize, int cur, int **visRow, int **visCol, int **visPart){
    while(cur < boardSize && board[cur/9][cur%9] != '.' ) cur++;  //跳过不为空的格子
    if(cur == boardSize){
        //已经找到一种解,将结果拷贝到result数组中
        for(int i = 0; i < boardSize/9; i++){
            for(int j = 0; j < boardSize/9; j++){
                result[i][j] = board[i][j];
            }
        }
        return ;
    }
    
    for(int i = 0; i < 9; i++){
        //对这个空的格子,依次放入1-9,看是否合法,若合法,递归求解
        if (cur < boardSize && visRow[cur/9][i] == 0 && visCol[cur%9][i] == 0 && visPart[cur/27*3+(cur%9)/3][i] == 0){
            board[cur/9][cur%9] = i+1+'0';
            visRow[cur/9][i] = 1;        //行                  
            visCol[cur%9][i] = 1;        //列
            visPart[cur/27*3+(cur%9)/3][i] = 1;  //小九宫格
            sudokuSolution(result,board,boardSize,cur+1,visRow,visCol,visPart);
            //现场还原
            board[cur/9][cur%9] = '.';
            visRow[cur/9][i] = 0;                           
            visCol[cur%9][i] = 0;
            visPart[cur/27*3+(cur%9)/3][i] = 0;
        }	
    }
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int **visRow = (int **)malloc(sizeof(int *)*boardRowSize);
    int **visCol = (int **)malloc(sizeof(int *)*boardRowSize);
    int **visPart = (int **)malloc(sizeof(int *)*boardRowSize);
    char **tab = (char **)malloc(sizeof(char *)*boardRowSize);
    for(int i = 0; i < boardRowSize; i++){
        *(visRow+i) = (int *)malloc(sizeof(int)*boardColSize);
        memset(*(visRow+i),0,sizeof(int)*boardColSize);
        *(visCol+i) = (int *)malloc(sizeof(int)*boardColSize);
        memset(*(visCol+i),0,sizeof(int)*boardColSize);
        *(visPart+i) = (int *)malloc(sizeof(int)*boardColSize);
        memset(*(visPart+i),0,sizeof(int)*boardColSize);
        *(tab+i) = (char *)malloc(sizeof(char)*boardColSize);
        memset(*(tab+i),0,sizeof(char)*boardColSize);
    }
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            if(board[i][j] != '.'){
                visRow[i][board[i][j]-'1'] = 1;
                visCol[j][board[i][j]-'1'] = 1;
                visPart[j/3+(i/3)*3][board[i][j]-'1'] = 1;
            }
            tab[i][j] = board[i][j];
        }
    }
    sudokuSolution(board,tab,boardRowSize*boardColSize,0,visRow,visCol,visPart);
}