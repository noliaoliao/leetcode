int maxProfit(int* prices, int pricesSize) {
    //lMaxProfit[]保存0~i的最大利润
    //rMaxProfit[]保存i~pricesSize-1的最大利润
    int *lMaxProfit = (int *)malloc(sizeof(int)*(pricesSize+1));
    int *rMaxProfit = (int *)malloc(sizeof(int)*(pricesSize+1));

    int minPrice = prices[0];
    lMaxProfit[0] = 0;
    for(int i = 1; i < pricesSize; i++){
        lMaxProfit[i] = prices[i]-minPrice > lMaxProfit[i-1] ? prices[i]- minPrice : lMaxProfit[i-1];
        minPrice = prices[i] < minPrice ? prices[i] : minPrice;
    }

    int maxPrice = prices[pricesSize-1];
    rMaxProfit[pricesSize-1] = 0;
    for(int i = pricesSize-2; i >= 0; i--){
        rMaxProfit[i] = maxPrice-prices[i] > rMaxProfit[i+1] ? maxPrice-prices[i] : rMaxProfit[i+1];
        maxPrice = prices[i] > maxPrice ? prices[i] : maxPrice;
    }

    //进行搜索
    int nMaxProfit = 0;
    for(int i = 1; i < pricesSize; i++){
        if(lMaxProfit[i]+rMaxProfit[i] > nMaxProfit){
            nMaxProfit = lMaxProfit[i]+rMaxProfit[i];
        }
    }
    return nMaxProfit;
}