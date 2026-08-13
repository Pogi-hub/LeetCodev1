#define buy 1
#define sell 0
class Solution {
public:
    int recurse(vector<int> &prices,vector<vector<int>> &dp,int i,int action){
        if(i==prices.size()) return 0;
        if(dp[i][action]!=-1) return dp[i][action];
        int profit=0;
        if(action){ //buy
            profit=max(-prices[i]+recurse(prices,dp,i+1,sell),recurse(prices,dp,i+1,buy));
        }
        else{       //sell
            profit=max(prices[i]+recurse(prices,dp,i+1,buy),recurse(prices,dp,i+1,sell));
        }
        return dp[i][action]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(),vector<int> (2,-1));
        return recurse(prices,dp,0,buy);
    }
};