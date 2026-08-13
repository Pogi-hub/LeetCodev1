#define buy 1
#define sell 0
class Solution {
public:
    int recurse(vector<int> &prices,vector<vector<vector<int>>> &dp,int i,int action,int cap){
        if(i==prices.size() || cap>=4) return 0;
        if(dp[i][action][cap]!=-1) return dp[i][action][cap];
        int profit=0;
        if(action){ //buy
            profit=max(-prices[i]+recurse(prices,dp,i+1,sell,cap+1),
                        recurse(prices,dp,i+1,buy,cap));
        }
        else{       //sell
            profit=max(prices[i]+recurse(prices,dp,i+1,buy,cap+1),
                        recurse(prices,dp,i+1,sell,cap));
        }
        return dp[i][action][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (4,-1)));
        return recurse(prices,dp,0,buy,0);
    }
};