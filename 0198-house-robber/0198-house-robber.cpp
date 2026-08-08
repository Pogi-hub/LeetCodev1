class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        if(n>=2) dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int pick=dp[i-2]+nums[i];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }

        return dp[n-1];
    }
};