class Solution {
public:
    int largestRectangleArea(int* height, int len) {
        //height.push_back(0);
        stack<int> s;
        int i = 0;
        int nMaxArea = 0;
        for(int i = 0; i < len; i++){
            if(s.empty() == true || height[s.top()] <= height[i]){
                s.push(i);
            }else{
                int nTopCur = s.top();
                s.pop();
                if(nMaxArea < (s.empty()? i : i-s.top()-1)*height[nTopCur]){
                    nMaxArea = (s.empty()? i : i-s.top()-1)*height[nTopCur];
                }
                i--;
            }
        }
        return nMaxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        //以每一行作为x坐标,为matrix的每一行生成height数组
        //数组的值即该上往上数连续1的个数
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        int** height = (int**)malloc(sizeof(int*)*nRows);
        for(int i = 0; i < nRows;i++){
            *(height+i) = (int*)malloc(sizeof(int)*(nCols+1));
            memset(*(height+i),0,sizeof(int)*(nCols+1));
        }

        //生成height数组
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                if(matrix[i][j] == '0'){
                    height[i][j] = 0;
                }else{
                    height[i][j] = ((i == 0) ? 1 : (height[i-1][j]+1));
                }
            }
        }

        //计算每个height数组能形成的矩形最大值
        int nMaxArea = 0;
        for(int i = 0; i < nRows; i++){
            int nCurMaxArea = largestRectangleArea(height[i],nCols+1);
            if(nCurMaxArea > nMaxArea) nMaxArea = nCurMaxArea;
        }

        return nMaxArea;
    }
};