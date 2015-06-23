class Solution {
public:
    int calculate(string s) {
        string slocal;
        //去掉所有的空格
        for(int i = 0; i < s.length(); i++){
            if(s[i] != 32){
                slocal += s[i];
            }
        }

        int temp = 0;
        for(int i = 0; i < slocal.length(); i++){
            if(slocal[i] >= '0' && slocal[i] <= '9'){
                temp = (temp*10+slocal[i]-'0');
            }else if(slocal[i] == '+' || slocal[i] == '-'){
                opt.push(temp);
                temp = 0;
                //持续计算,如果操作符栈不为空
                while(!opr.empty()){
                    calconce();
                }
                opr.push(slocal[i]); 
            }else if(slocal[i] == '*' || slocal[i] == '/'){
                opt.push(temp);
                temp = 0;
                //操作符栈不为空,且栈顶为*/
                if(!opr.empty() && (opr.top() == '*' || opr.top() == '/')){
                    calconce();
                }
                opr.push(slocal[i]);
            }else{
                return 0;
            }
        }
        opt.push(temp);

        //处理剩下的栈空间
        if(opt.empty()) return 0;
        while(!opr.empty()){
            calconce();
        }

        return opt.top();
    }

    //根据opr栈顶的操作符,opt栈中的操作数来进行一次四则运算
    //将结果压入栈中
    void calconce(){
        char oprt = opr.top();
        opr.pop();
        int val2 = opt.top();
        opt.pop();
        int val1 = opt.top();
        opt.pop();
        switch(oprt){
        case '+':
            opt.push(val1+val2);
            break;
        case '-':
            opt.push(val1-val2);
            break;
        case '*':
            opt.push(val1*val2);
            break;
        case '/':
            opt.push(val1/val2);
            break;
        default:
            break;
        }
    }

private:
    stack<int> opt;
    stack<char> opr;
};