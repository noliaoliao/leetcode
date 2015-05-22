int divide(int dividend, int divisor){  
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
        return INT_MAX;
    }
    if(dividend == divisor){
        return 1;
    }
    if(dividend == 0 || divisor == INT_MIN){
        return 0;
    }
    unsigned a = abs(dividend);
    unsigned b = abs(divisor);
    int result = 0;

    while (a >= b){  
        int count = 0;  
        while (a >= b<<count){  
            result += 1<<count;  
            a -= b<<count;  
            count++;  
        }             
    }  
    return (dividend > 0) ^ (divisor > 0) ? -result : result;  
} 