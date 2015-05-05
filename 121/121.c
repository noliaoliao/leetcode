//遍历一遍数组
//维护i之前的最小值及最大的差值
//差值最大值即所能获得的最大利润
int maxProfit(int* prices, int pricesSize) {
    int i = 0;
    int minPrice = prices[0];
    int maxPrice = 0;
    for(i = 0; i < pricesSize; i++){
        if(minPrice > prices[i]) minPrice = prices[i];
        if(prices[i]-minPrice > maxPrice) maxPrice = prices[i]-minPrice;
    }
    
    return maxPrice;
}