#define buy 1
#define sell 0
class Solution {
public:
    int recurse(int i,int k,int cap, int action,
                vector<int> & prices,
                vector<vector<vector<int>>> &dp){
        if(i>=prices.size() || k>=cap) return 0;

        if(dp[i][action][k]!=-1) return dp[i][action][k];

        int profit=0;
        if(action==buy){
            profit=max(-prices[i]+recurse(i+1,k+1,cap,sell,prices,dp),
                        recurse(i+1,k,cap,buy,prices,dp));
        }
        else{
            profit=max(prices[i]+recurse(i+1,k+1,cap,buy,prices,dp),
                        recurse(i+1,k,cap,sell,prices,dp));
        }

        return dp[i][action][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k*2,-1)));
        return recurse(0,0,k*2,buy,prices,dp);
    }
};