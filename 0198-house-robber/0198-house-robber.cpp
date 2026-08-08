class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int prev1=nums[0];
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int prev2=max(nums[0],nums[1]);
        int curr=0;

        for(int i=2;i<n;i++){
            int pick=prev1+nums[i];
            int notpick=prev2;
            curr=max(pick,notpick);
            prev1=prev2;
            prev2=curr;
        }

        return curr;
    }
};