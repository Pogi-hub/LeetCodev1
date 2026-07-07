class Solution {
public:
    int solve(vector<int>& coins,int idx,int T,vector<vector<int>> &dp) {
        if(idx==0) return T%coins[0]==0;

        if(dp[idx][T]!=-1) return dp[idx][T];

        int notpick= solve(coins,idx-1,T,dp);

        int pick=0;
        if(coins[idx]<=T)
        pick=solve(coins,idx,T-coins[idx],dp);

        return dp[idx][T]= pick+notpick;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,coins.size()-1,amount,dp);
    }
};