//��������,ֻҪ�е�׬�ͽ���һ������

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    int i = 0;
    if(pricesSize == 0) return 0;
    for(i = 1; i < pricesSize; i++){
        if(prices[i] > prices[i-1]){
            ans += prices[i]-prices[i-1];
        }
    }
    return ans;
}