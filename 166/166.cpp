//166 Fraction to Recurring Decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        //INT_MIN会溢出,因此需要转换为long long int
        //转换完后之后依旧是负数,因此要求一次abs
        long long int dividend = numerator; 
        dividend = abs(dividend);
        long long int divisor = denominator;
        divisor = abs(divisor);
        string res = (numerator < 0 ^ denominator < 0)  ? "-" : "";
        unordered_map<int,int> hmap;  //保存出现过的余数

        //得到整数部分
        long long int remainder = dividend / divisor;
        long long int quotient = dividend % divisor;
        res += to_string(remainder);
        if(quotient == 0) return res;
        res += ".";
        hmap[quotient] = res.length();

        while(quotient != 0){
            quotient *= 10;
            remainder = quotient / divisor;
            quotient = quotient % divisor;
            res += to_string(remainder);
            unordered_map<int,int>::iterator iter = hmap.find(quotient);
            if(iter != hmap.end()){
                //余数出现过了,开始循环
                res.insert(iter->second,"(");
                res += ')';
                break;
            }
            //记录余数的位置,即res的长度
            hmap[quotient] = res.length();
        }

        return res;
    }
};