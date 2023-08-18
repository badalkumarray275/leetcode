class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
              
           int n = prices.size();
          int aheadNotBuy =0;
          int   aheadBuy  =0;
 
          for(int ind =n-1;ind>=0;ind--)
          {
              for(int buy=0;buy<2;buy++)
              {
                   
                   int currNotBuy = max(prices[ind] + aheadBuy ,0 +aheadNotBuy);
                   int  currBuy = max(-prices[ind]-fee +  aheadNotBuy,0+aheadBuy);
                   aheadNotBuy = currNotBuy;
                   aheadBuy = currBuy;
              }
            
          }
          return aheadBuy;
    }
};