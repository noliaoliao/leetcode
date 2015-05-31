class Solution {
public:
    string calcExpression(string op1, string op2, string oper){
        int val1 = atoi(op1.c_str());
        int val2 = atoi(op2.c_str());
        int res = 0;
        switch(oper[0]){
        case '+':
            res = val1 + val2;
            break;
        case '-':
            res = val1 - val2;
            break;
        case '*':
            res = val1 * val2;
            break;
        case '/':
            res = val1 / val2;
            break;
        }
        char buf[32];
        sprintf(buf,"%d",res);
        string s(buf);
        return s;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i].compare("+") == 0 || \
                tokens[i].compare("-") == 0 || \
                tokens[i].compare("*") == 0 || \
                tokens[i].compare("/") == 0){
                if(s.size() < 2) return 0;
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                s.push(calcExpression(op2,op1,tokens[i]));
            }else{
                s.push(tokens[i]);
            }
        }

        return atoi(s.top().c_str());
    }
};