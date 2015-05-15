class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);  //在末尾压入一个0,代表结束
        stack<int> s;
        int i = 0;
        int nMaxArea = 0;
        for(int i = 0; i < height.size(); i++){
            //栈为空或者当前栈顶height<=当前height,入栈
            if(s.empty() == true || height[s.top()] <= height[i]){
                s.push(i);
            }else{
                //否则出栈,计算面积
                int nTopCur = s.top();
                s.pop();
                if(nMaxArea < (s.empty()? i : i-s.top()-1)*height[nTopCur]){
                    nMaxArea = (s.empty()? i : i-s.top()-1)*height[nTopCur];
                }
                i--;  //依次比较,栈里面保存的是递增序列
            }
        }
        return nMaxArea;
    }
};