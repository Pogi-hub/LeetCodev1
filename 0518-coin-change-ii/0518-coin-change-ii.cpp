class Solution {
public:
    using ll=long long;
    //memorization method
    int mem(vector<int>& coins,int idx,int T,vector<vector<int>> &dp) {
        if(idx==0) return T%coins[0]==0;

        if(dp[idx][T]!=-1) return dp[idx][T];

        int notpick= mem(coins,idx-1,T,dp);

        int pick=0;
        if(coins[idx]<=T)
        pick=mem(coins,idx,T-coins[idx],dp);

        return dp[idx][T]= pick+notpick;
    }

    int tab(int T, vector<int>& coins,vector<vector<ll>> &dp){
        for(int i=0;i<=T;i++){
            dp[0][i]=(i%coins[0]==0);
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<=T;amt++){

                ll notpick=dp[i-1][amt];

                ll pick=0;
                if(coins[i]<=amt ) pick=dp[i][amt-coins[i]];

                dp[i][amt]= pick+notpick;
                if(dp[i][amt]>INT_MAX) dp[i][amt]=0;
            }
        }

        return (int)dp[coins.size()-1][T];
    }

    int change(int amount, vector<int>& coins) {
        //for memorisation
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        //for tabulation
        vector<vector<ll>> dp(coins.size(),vector<ll>(amount+1,0));
        // return mem(coins,coins.size()-1,amount,dp);
        return tab(amount,coins,dp);
    }
};