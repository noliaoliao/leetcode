class Solution {
public:
    int longestValidParentheses(string s) {
        int nMaxValidLen = 0;
        int nBegin = -1;
        stack<int> bracket;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                //左括号无条件入栈
                bracket.push(i);
            }else{
                //右括号
                if(!bracket.empty()){
                    //栈不为空,弹出栈顶的一个'('
                    bracket.pop();
                    if(bracket.empty()){
                        //弹出一个'('后,栈为空,则当前长度为i-nBegin
                        //考虑()()),第二个
                        nMaxValidLen = MAX(i-nBegin,nMaxValidLen);
                    }else{
                        //不为空,考虑(()()
                        nMaxValidLen = MAX(i-bracket.top(),nMaxValidLen);
                    }
                }else{
                    //栈空,更新nBegin的值
                    nBegin = i;
                }
            }
        }
        return nMaxValidLen;
    }
};