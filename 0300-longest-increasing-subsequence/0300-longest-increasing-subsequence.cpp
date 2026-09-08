class Solution {
public:
    int recurse(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notpick=recurse(nums,i+1,prev,dp);
        int pick=0;
        if(prev==-1 || nums[i]>nums[prev]){
            pick=1+recurse(nums,i+1,i,dp);
        }
        return dp[i][prev+1]=max(pick,notpick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int len=dp[i+1][prev+1];
                if(prev==-1||nums[i]>nums[prev]){
                    len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][prev+1]=len;

            }
        }
        return dp[0][0];
    }
};