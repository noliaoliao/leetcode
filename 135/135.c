int candy(int* ratings, int ratingsSize) {
    if(ratingsSize <= 0) return 0;
    int *candys = (int *)malloc(sizeof(int)*ratingsSize);
    memset(candys,0,sizeof(int)*ratingsSize);
    candys[0] = 1;
    for(int i = 1; i < ratingsSize; i++){
        if(ratings[i] > ratings[i-1]){
            candys[i] = candys[i-1]+1;
        }else{
            candys[i] = 1;
        }
    }

    int nMinCandys = candys[ratingsSize-1];
    for(int i = ratingsSize-2; i >= 0; i--){
        int curr = 1;
        if(ratings[i] > ratings[i+1]){
            curr = candys[i+1]+1; 
        }
        nMinCandys += (curr > candys[i] ? curr : candys[i]);
        candys[i] = curr;
    }

    return nMinCandys;    
}