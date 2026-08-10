class Solution {
public:
    int recurse2(vector<int> &coins,int sum,int amt,vector<int> &dp){
        if(sum==amt) return 0;

        if(sum>amt) return 1e9;
        int ans=1e9;
        
        if(dp[sum]!=-1) return dp[sum];

        for(int i=0;i<coins.size();i++){
            if (coins[i] <= amt - sum) 
            ans = min(ans, 1 + recurse2(coins, sum + coins[i], amt, dp));
        }

        return dp[sum]=ans;
    }
    int recurse1(vector<int> &coins,int i,int sum,int amt){
        if(sum==amt) return 0;
        if(i==coins.size()) return 1e9;

        int notpick=recurse1(coins,i+1,sum,amt);

        int pick=1e9;
        if(coins[i]+sum<=amt) pick=1+recurse1(coins,i,sum+coins[i],amt);

        return min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // if(amount==0) return 0;
        // int ans=recurse1(coins,0,0,amount);
        // if(ans==1e9) return -1;
        // return ans;

        //recurse 2 approach
        vector<int> dp (amount+1,1e9);
        // if(amount==0) return 0;
        // int ans=recurse2(coins,0,amount,dp);
        // if(ans==1e9) return -1;
        // return ans;
        int n=coins.size();
        
        dp[0]=0;

        for(int sum=0;sum<=amount;sum++){
            for(int i=0;i<n;i++){
                if (coins[i] <= sum) 
                dp[sum] = min(dp[sum], 1 + dp[sum-coins[i]]);
            }
        }

        if(dp[amount]==1e9) return -1;
        return dp[amount];
        
    }
};