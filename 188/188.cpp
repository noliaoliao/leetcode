#define MAX(A,B) ((A)>(B)?(A):(B))

class Solution {
public:
    int maxProfit(int k, vector<int> &prices){
        int nDays = prices.size();
        if(nDays <= 0) return 0;
        //当k大于days的时候,直接调用不限次数的解法即可
        if(nDays <= k) return maxProfitNolimit(prices);
        
        //local[i][j]表示进行到i天,j次交易获得的最大利润,且最后一次交易在当天
        //global[i][j]表示进行到i天,j次交易获得的最大利润,代表全局
        vector<vector<int>> local(nDays,vector<int>(k+1));
        vector<vector<int>> global(nDays,vector<int>(k+1));
        for(int i = 1; i < nDays; i++){
            int diff = prices[i]-prices[i-1];
            for(int j = 1; j <= k; j++){
                //local[i][j]取以下两者的最大值
                //  1.前i-1天进行j-1次交易的利润,加上第i天当天进行交易的利润(大于等于0)
                //  2.前i-1天进行j次交易,加上i天的差值,表示i天卖出,这样交易次数不变
                //global[i][j]取以下两者的最大值
                //  1.全局i-1天j次交易的最大值
                //  2.当前i天j次交易的最大值
                local[i][j] = MAX(global[i-1][j-1]+MAX(diff,0),local[i-1][j]+diff);
                global[i][j] = MAX(global[i-1][j],local[i][j]);
            }
        }

        return global[nDays-1][k];

    }

    int maxProfitNolimit(vector<int> &prices){
        int ans = 0;
        int i = 0;
        if(prices.size() == 0) return 0;
        for(i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                ans += prices[i]-prices[i-1];
            }
        }
        return ans;
    }
};