class Solution {
public:
    int maxSum_lessthanGoal(vector<int>& nums, int goal){

        if(goal<0) return 0;

        int sum=0,count=0,l=0,r=0;
        int len=nums.size();

        for(r=0;r<len;r++){
            sum+=nums[r];

            while(sum>goal && l<len){
                sum-=nums[l];
                l++;
            }

            count+=(r-l+1);
        }

        return count;
        
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maxSum_lessthanGoal(nums,goal)-maxSum_lessthanGoal(nums,goal-1);
    }
    
};